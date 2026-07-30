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
vector<pii> G[N];
int vis[N];

struct LCA {
    vector<int> depth;
    vector<vector<int>> par, dis;
    LCA(int _n) : depth(_n + 1), par(20, vector<int>(_n + 1)), dis(20, vector<int>(_n + 1)) {}
    void dfs(int v, int p, int col) {
        vis[v] = col;
        depth[v] = (p == -1 ? 0ll : depth[p] + 1);
        for (auto &[u, w] : G[v]) {
            if (u == p) continue;
            par[0][u] = v;
            dis[0][u] = w;
            dfs(u, v, col);
        }
    }
    void build(int n) {
        for (int i = 1; i < 20; i++)
            for (int j = 1; j <= n; j++) {
                par[i][j] = par[i - 1][par[i - 1][j]];
                dis[i][j] = max(dis[i - 1][j], dis[i - 1][par[i - 1][j]]);
            }
    }
    pii lca(int v, int u) { // {vertex, distance}
        if (depth[v] < depth[u]) swap(v, u);
        int step = depth[v] - depth[u], res = 0;
        for (int i = 0; i < 20; i++)
            if ((step >> i) & 1) {
                res = max(res, dis[i][v]);
                v = par[i][v];
            }
        if (v == u) return {v, res};
        for (int i = 19; i >= 0; i--)
            while (par[i][v] != par[i][u]) {
                res = max({res, dis[i][v], dis[i][u]});
                v = par[i][v];
                u = par[i][u];
            }
        res = max({res, dis[0][v], dis[0][u]});
        v = par[0][v];
        return {v, res};
    }
};

struct DSU {
    vector<int> dsu, sz;
    DSU(int _n) : dsu(_n + 1), sz(_n + 1) {
        for (int i = 1; i <= _n; i++) {
            dsu[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x) {
        if (x == dsu[x]) return x;
        return dsu[x] = find(dsu[x]);
    }
    bool merge(int x, int y) {
        int xx = find(x), yy = find(y);
        if (xx == yy) return false;
        if (sz[xx] < sz[yy]) swap(xx, yy);
        dsu[yy] = xx;
        sz[xx] += sz[yy];
        return true;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

signed main() {
    IO;
    int n, q, o, a, b, k;
    cin >> n >> q;
    DSU dsu(n);
    vector<vector<int>> qry(q + 1);
    FOR (i, 1, q) {
        cin >> o;
        if (o == 1) {
            cin >> a >> b;
            if (! dsu.same(a, b)) {
                G[a].push_back({b, i});
                G[b].push_back({a, i});
                dsu.merge(a, b);
            }
        } else {
            cin >> k;
            while (k--) {
                cin >> a;
                qry[i].push_back(a);
            }
        }
    }
    LCA A(n);
    int cnt = 0;
    FOR (i, 1, n) {
        if (vis[i] == 0) {
            A.dfs(i, -1, cnt);
            cnt += 1;
        }
    }
    A.build(n);
    FOR (i, 1, q) {
        if (! qry[i].empty()) {
            int ans = -1;
            FOR (j, 1, siz(qry[i]) - 1) {
                if (vis[qry[i][0]] != vis[qry[i][j]]) {
                    ans = -1;
                    break;
                }
                ans = max(ans, A.lca(qry[i][0], qry[i][j]).S);
            }
            if (ans > i) ans = -1;
            cout << ans << "\n";
        }
    }
}