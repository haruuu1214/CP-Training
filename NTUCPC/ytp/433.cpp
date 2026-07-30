#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define siz(x) (int)x.size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// ---------------------------------------------

const int N = 200005;
const int mod = 998244353;
int a[N], qry[N];
int to[N];
int seg[4 * N];
vector<int> num;

#define lc (node << 1)
#define rc ((node << 1) | 1)
void update(int node, int l, int r, int id, int va) {
    if (l == r) {
        seg[node] = va;
        return;
    }
    int mid = (l + r) >> 1;
    if (id <= mid)
        update(lc, l, mid, id, va);
    else
        update(rc, mid + 1, r, id, va);
    seg[node] = min(seg[lc], seg[rc]);
}

int query(int node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
        return seg[node];
    int mid = (l + r) >> 1;
    if (qr <= mid)
        return query(lc, l, mid, ql, qr);
    else if (mid + 1 <= ql)
        return query(rc, mid + 1, r, ql, qr);
    else
        return min(query(lc, l, mid, ql, qr), query(rc, mid + 1, r, ql, qr));
    seg[node] = min(seg[lc], seg[rc]);
}

int getl(int x) {
    return lower_bound(all(num), x) - num.begin() + 1;
}

int getr(int x) {
    return upper_bound(all(num), x) - num.begin();
}

vector<int> G[N];
pii dp[N];
int in[N];

void dfs(int v) {
    for (int u : G[v]) {
        dp[u] = {dp[v].F + a[u], dp[v].S};
        dfs(u);
    }
}

struct BIT {
    vector<int> bit;
    int n;
    BIT(int _n) : n(_n), bit(_n + 1) {}
    void update(int id, int va) {
        for (int i = id; i <= n; i += i & -i)
            bit[i] += va;
    }
    int query(int id) {
        int sum = 0;
        for (int i = id; i > 0; i -= i & -i)
            sum += bit[i];
        return sum;
    }
};

signed main() {
    IO;
    int n, k;
    cin >> n >> k;
    fill(seg, seg + 4 * N, n + 1);
    FOR (i, 1, n) {
        cin >> a[i];
        num.push_back(a[i]);
    }
    sort(all(num));
    num.resize(unique(all(num)) - num.begin());


    for (int i = n; i >= 1; i--) {
        int x = query(1, 1, n, getl(a[i] - k), getr(a[i] + k));
        to[i] = x;
        update(1, 1, n, getl(a[i]), i);
    }
    // for (int i = 1; i <= n; i++) cout << to[i] << " \n"[i == n];

    for (int i = 1; i <= n; i++) {
        if (to[i] != n + 1) {
            in[i] += 1;
            G[to[i]].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (! in[i]) {
            dp[i] = {a[i], a[i]};
            dfs(i);
        }
    }
    BIT bit(n);
    for (int i = 1; i <= n; i++)
        bit.update(getl(dp[i].S), dp[i].F);
    
    int q, p;
    cin >> q;
    FOR (i, 1, q) {
        cin >> p;
        cout << bit.query(n) - bit.query(getl(p) - 1) << "\n";
    }
}