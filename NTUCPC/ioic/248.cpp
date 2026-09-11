#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define sz(a) ((int)a.size())
#define pb push_back
#define IO ios::sync_with_stdio(), cin.tie(0)
using namespace std;
void debug() { cerr << endl; }
template <typename T, typename ...U>
void debug(T i, U ...j) { cerr << i << ' ', debug(j...); }

const int N = 305, M = 50005, INF = 1e18;
int adj[N][N];
multiset<pii> G[N];
struct Edge {
    int v, u, w;
};

signed main() {
    IO;
    int n, m, a, b, c;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        --a; --b;
        edges[i] = {a, b, c};
    }
    sort(all(edges), [&](Edge e1, Edge e2) {
        return e1.w < e2.w;
    });
    int ans = INF;
    int comp = n;
    multiset<int> all_w;
    for (auto [v, u, w]: edges) {
        vector<int> dis(n, INF);
        vector<pii> from(n);
        queue<pii> Q;
        Q.push({v, 0});
        from[v] = {-1, -1};
        dis[v] = 0;
        while (! Q.empty()) {
            auto [cur, cur_d] = Q.front();
            Q.pop();
            if (cur_d != dis[cur]) continue;
            for (auto [nxt, weight]: G[cur]) {
                if (cur_d + weight < dis[nxt]) {
                    Q.push({nxt, cur_d + weight});
                    dis[nxt] = cur_d + weight;
                    from[nxt] = {cur, weight};
                }
            }
        }
        if (dis[u] == INF) {
            comp -= 1;
        } else {
            // find smallest edge
            int min_v, min_u, min_w = INF;
            int cur = u;
            while (cur != v) {
                if (from[cur].S < min_w) {
                    min_v = cur;
                    min_u = from[cur].F;
                    min_w = from[cur].S;
                }
                cur = from[cur].F;
            }
            G[min_v].erase(G[min_v].find({min_u, min_w}));
            G[min_u].erase(G[min_u].find({min_v, min_w}));
            all_w.erase(all_w.find(min_w));
            // debug("erase", min_v, min_u, min_w);
        }
        G[v].insert({u, w});
        G[u].insert({v, w});
        all_w.insert(w);
        // debug("insert", v, u, w);
        if (comp == 1) {
            int res = w - *all_w.begin();
            ans = min(ans, res);
        }
    }
    cout << ans << '\n';
}