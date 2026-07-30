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
vector<pii> G[N];

struct LCA {
    vector<int> depth;
    vector<vector<int>> par, dis;
    LCA(int _n) : depth(_n + 1), par(20, vector<int>(_n + 1)), dis(20, vector<int>(_n + 1)) {}
    void dfs(int v, int p) {
        depth[v] = (p == -1 ? 0ll : depth[p] + 1);
        for (auto &[u, w] : G[v]) {
            if (u == p) continue;
            par[0][u] = v;
            dis[0][u] = w;
            dfs(u, v);
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
pii E[N];
int ti[N];

signed main() {
    IO;
    int n, m, x;
    cin >> n >> m;
    FOR (i, 1, m) cin >> E[i].F >> E[i].S;
    vector<pair<pii, int>> order;
    FOR (i, 1, n - 1) {
        cin >> x;
        ti[x] = -1;
        order.push_back({E[x], x});
    }
    sort(all(order));
    int cnt = 0;
    for (auto &[p, i] : order) {
        cnt += 1;
        i = cnt;
        G[p.F].push_back({p.S, i});
        G[p.S].push_back({p.F, i});
    }
    LCA lca(n);
    lca.dfs(1, -1);
    lca.build(n);
    priority_queue<pair<pii, int>, vector<pair<pii, int>>, greater<pair<pii, int>>> ok;
    vector<pair<pii, int>> order2;
    FOR (i, 1, m) {
        if (ti[i] != -1) {
            ti[i] = lca.lca(E[i].F, E[i].S).S;
            // cout << E[i].F << " " << E[i].S << " " << ti[i] << "\n";
            order2.push_back({E[i], ti[i]});
        }
    }
    for (auto [p, i] : order) ok.push({p, i});
    sort(all(order2), [&](pair<pii, int> p1, pair<pii, int> p2) {
        return p1.S > p2.S;
    });
    while (! ok.empty()) {
        pair<pii, int> cur = ok.top(); ok.pop();
        cout << cur.F.F << " " << cur.F.S << "\n";
        if (cur.S > 0) {
            int w = cur.S;
            while (! order2.empty() && order2.back().S == w) {
                ok.push({order2.back().F, 0});
                order2.pop_back();
            }
        }
    }
}