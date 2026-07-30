// https://www.cnblogs.com/cj-chd/p/10285814.html
#include <bits/stdc++.h>
using namespace std;
const int N = 100005, inf = 1e9;
int deg[N], dp[N][2], par[N], dfn[N], low[N], val[N], t;
vector <int> g[N];

void dfs(int x, int h) {
    par[x] = h, dfn[x] = low[x] = ++t, dp[x][1] = val[x], dp[x][0] = 0;
    int y;
    for (int i = 0; i < deg[x]; ++i) {
        if (!dfn[y = g[x][i]])
            dfs(y, x), low[x] = min(low[x], low[y]);
        else
            if (y != h)
                low[x] = min(low[x], dfn[y]);
        if(low[y] > dfn[x])
            dp[x][1] += dp[y][0], dp[x][0] += max(dp[y][0], dp[y][1]);
    }
    for (int i = 0; i < deg[x]; ++i)
        if (par[y = g[x][i]] != x && dfn[x] < dfn[y]) {
            int j, u[2], v[2];
            v[0] = v[1] = 0;
            for (j = y; j != x; j = par[j])
                u[0] = v[0] + dp[j][0], u[1] = v[1] + dp[j][1], v[0] = max(u[0], u[1]), v[1] = u[0];
            dp[x][0] += v[0], v[0] = 0, v[1] = -inf;
            for (j = y; j != x; j = par[j])
                u[0] = v[0] + dp[j][0], u[1] = v[1] + dp[j][1], v[0] = max(u[0], u[1]), v[1] = u[0];
            dp[x][1] += v[1];
        }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> val[i];
    for (int i = 1; i <= m; ++i)
        cin >> x >> y, g[x].push_back(y), g[y].push_back(x);
    for (int i = 1; i <= n; ++i)
        deg[i] = g[i].size();
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]);
    return 0;
}