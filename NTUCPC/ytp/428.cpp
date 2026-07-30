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

const int N = 500005;
const int mod = 998244353;

int n, dis1[N], dis2[N];
vector<pii> G[N];

void solve1(int s = 1, int t = n) {
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    fill(dis1, dis1 + N, 1e18);
    dis1[s] = 0;
    Q.push({dis1[s], s});
    while (! Q.empty()) {
        auto [step, v] = Q.top(); Q.pop();
        if (dis1[v] != step) continue;
        for (auto [u, w] : G[v]) {
            if (step + w < dis1[u]) {
                dis1[u] = step + w;
                Q.push({dis1[u], u});
            }
        }
    }
}

void solve2(int s = n, int t = 1) {
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    fill(dis2, dis2 + N, 1e18);
    dis2[s] = 0;
    Q.push({dis2[s], s});
    while (! Q.empty()) {
        auto [step, v] = Q.top(); Q.pop();
        if (dis2[v] != step) continue;
        for (auto [u, w] : G[v]) {
            if (step + w < dis2[u]) {
                dis2[u] = step + w;
                Q.push({dis2[u], u});
            }
        }
    }
}

signed main() {
    IO;
    int m, k, v, u, w;
    cin >> n >> m >> k;
    FOR (i, 1, m) {
        cin >> v >> u >> w;
        G[v].push_back({u, w});
        G[u].push_back({v, w});
    }
    solve1();
    solve2();
    int ans = dis1[n];
    FOR (i, 1, k) {
        cin >> v >> u >> w;
        ans = min(ans, dis1[v] + dis2[u] + w);
        ans = min(ans, dis1[u] + dis2[v] + w);
    }
    if (ans == 1e18) ans = -1;
    cout << ans;
}