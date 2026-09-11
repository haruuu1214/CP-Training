#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
void debug() { cerr << endl; }
template <typename T, typename ...U>
void debug(T i, U ...j) { cerr << i << ' ', debug(j...); }
#define test(...) debug("[" #__VA_ARGS__ "]:", __VA_ARGS__)

struct Segment_Tree {
    vector<int> tree, add;
    int n;
    Segment_Tree(int _n) : n(_n + 1), tree(4 * _n + 5), add(4 * _n + 5) {}
    #define lc (node << 1)
    #define rc (node << 1 | 1)
    void push(int node, int l, int r) {
        if (add[node]) {
            int mid = (l + r) >> 1;
            tree[lc] += add[node] * (mid - l + 1);
            tree[rc] += add[node] * (r - mid);
            add[lc] += add[node];
            add[rc] += add[node];
            add[node] = 0;
        }
    }
    void update(int node, int l, int r, int ql, int qr, int val) {
        if (ql <= l && r <= qr) {
            tree[node] += val * (r - l + 1);
            add[node] += val;
            return;
        }
        int mid = (l + r) >> 1;
        push(node, l, r);
        if (qr <= mid)
            update(lc, l, mid, ql, qr, val);
        else if (mid + 1 <= ql)
            update(rc, mid + 1, r, ql, qr, val);
        else {
            update(lc, l, mid, ql, qr, val);
            update(rc, mid + 1, r, ql, qr, val);
        }
        tree[node] = tree[lc] + tree[rc];
    }
    int query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) >> 1;
        push(node, l, r);
        if (qr <= mid)
            return query(lc, l, mid, ql, qr);
        else if (mid + 1 <= ql)
            return query(rc, mid + 1, r, ql, qr);
        else
            return query(lc, l, mid, ql, qr) + query(rc, mid + 1, r, ql, qr);
    }
};

const int N = 500005;
int s[N];
int in[N], out[N], depth[N], timer, max_depth;
vector<int> G[N];
void dfs(int v, int d) {
    timer++;
    in[v] = timer;
    depth[v] = d;
    max_depth = max(max_depth, d);
    for (int u : G[v])
        dfs(u, d + 1);
    timer++;
    out[v] = timer;
}

signed main() {
	IO;
	int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        G[p].pb(i);
    }
    dfs(1, 0);
    Segment_Tree seg_tree(n);
    
    vector<vector<int>> depth_node(max_depth + 1, vector<int>());
    vector<int> node_id(n + 1), to_node(n + 1);
    for (int i = 1; i <= n; i++)
        depth_node[depth[i]].pb(i);
    
    for (int i = 0; i <= max_depth; i++)
        sort(all(depth_node[i]), [&](int a, int b) {
            return in[a] < in[b];
        });
    
    vector<vector<int>> depth_node_in(max_depth + 1, vector<int>());
    int nid = 0;
    for (int i = 0; i <= max_depth; i++) {
        for (int v : depth_node[i]) {
            node_id[v] = ++nid;
            to_node[nid] = v;
            depth_node_in[i].pb(in[v]);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        seg_tree.update(1, 1, n, node_id[i], node_id[i], s[i]);
    }


    int last = 0;
    while (q--) {
        int u, v, w, x, y, z;
        cin >> u >> v >> w >> x >> y >> z;
        int a = (u * (last % 1000000) + v) % 1000000;
        int b = (w * (last % n) + x) % n;
        int c = (y * (last % n) + z) % n + 1;
        int dep = min(max_depth, depth[c] + b);
        int l = lower_bound(all(depth_node_in[dep]), in[c]) - depth_node_in[dep].begin();
        int r = upper_bound(all(depth_node_in[dep]), out[c]) - depth_node_in[dep].begin() - 1;
        if (l <= r) {
            seg_tree.update(1, 1, n, node_id[depth_node[dep][l]], node_id[depth_node[dep][r]], a);
            last = seg_tree.query(1, 1, n, node_id[depth_node[dep][l]], node_id[depth_node[dep][r]]);
            cout << last << '\n';
        } else {
            last = 0;
            cout << last << '\n';
        }
    }
}