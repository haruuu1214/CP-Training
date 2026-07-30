
#include <bits/stdc++.h>
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << (sizeof...(b) ? ", " : "  "); dbg(b...);}
void ent() {cout << "\n";}
/// ------- Initialization End -------

const int N = 305;
const int M = 50005;
const int MAX = 1e8;

int dsu[N], sz[N];
stack<pair<int*, int>> undo_dsu, undo_sz;
int find(int x) {
    if (dsu[x] == x) return x;
    return find(dsu[x]);
}

int n, m;
int total_comp;
bool suc = false;

bool merge(int x, int y) {
    x = find(x); y = find(y);
    if (sz[x] < sz[y]) swap(x, y);
    if (x == y) return false;
    total_comp -= 1;
    undo_dsu.push({&dsu[y], dsu[y]});
    undo_sz.push({&sz[x], sz[x]});
    dsu[y] = x;
    sz[x] += sz[y];
    return true;
}

void undo() {
    total_comp += 1;
    * undo_dsu.top().first = undo_dsu.top().second;
    * undo_sz.top().first = undo_sz.top().second;
    undo_dsu.pop();
    undo_sz.pop();
}

const int SEG_SZ = 1e6;
int current_length = 0;
vector<vector<pii>> eve(SEG_SZ);
vector<int> lc(SEG_SZ);
vector<int> rc(SEG_SZ);

void push(int node) {
    if (lc[node] == -1) {
        lc[node] = current_length;
        eve[current_length].clear();
        lc[current_length] = -1;
        rc[current_length] = -1;
        current_length += 1;
    }
    if (rc[node] == -1) {
        rc[node] = current_length;
        eve[current_length].clear();
        lc[current_length] = -1;
        rc[current_length] = -1;
        current_length += 1;
    }
}

struct titree {
    void init() {
        current_length = 0;
        eve[current_length].clear();
        lc[current_length] = -1;
        rc[current_length] = -1;
        current_length += 1;
    }
    void insert(int node, int l, int r, int ql, int qr, pii event) {
        if (ql <= l && r <= qr) {
            eve[node].push_back(event);
            return;
        }
        int mid = (l + r) >> 1;
        push(node);
        if (qr <= mid)
            insert(lc[node], l, mid, ql, qr, event);
        else if (mid + 1 <= ql)
            insert(rc[node], mid + 1, r, ql, qr, event);
        else {
            insert(lc[node], l, mid, ql, qr, event);
            insert(rc[node], mid + 1, r, ql, qr, event);
        }
    }
    void traversal(int node, int l, int r) {
        int cnt = 0;
        for (auto [v, u] : eve[node]) {
            if (merge(v, u))
                cnt += 1;
        }
        eve[node].clear();
        if (lc[node] == -1 && rc[node] == -1) {
            if (total_comp == 1)
                suc = true;
        } else {
            int mid = (l + r) >> 1;
            if (lc[node] != -1) traversal(lc[node], l, mid);
            if (rc[node] != -1) traversal(rc[node], mid + 1, r);
        }
        while (cnt > 0) {
            undo();
            cnt -= 1;
        }
    }
} timeseg;

int v[M], u[M], w[M], from[M], to[M];
/*
[1, k + 1], [2, k + 2], ... [MAX - k, MAX]
*/
void build_time_range(int k) {
    for (int i = 1; i <= m; i++) {
        from[i] = max(1, w[i] - k);
        to[i] = min(MAX - k, w[i]);
    }
}
void insert_event(int k) {
    total_comp = n;
    suc = false;
    timeseg.init();
    for (int i = 1; i <= m; i++)
        timeseg.insert(0, 1, MAX - k, from[i], to[i], {v[i], u[i]});
}

/*
[1, 3] , [2, 4] , [3, 5]
*/

signed main() {
    IO;
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) dsu[i] = i;
    for (int i = 1; i <= n; i++) sz[i] = 1;
    for (int i = 1; i <= m; i++)
        cin >> v[i] >> u[i] >> w[i];
    int l = -1, r = MAX;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        build_time_range(mid);
        insert_event(mid);
        timeseg.traversal(0, 1, MAX - mid);
        if (suc)
            r = mid;
        else
            l = mid;
    }
    cout << r << "\n";
    
    return 0;
}