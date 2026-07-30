#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

vector<pii> G[200005];
int n;
int mx, pt;

void dfs(int v, int p, int cnt)
{
    if (cnt > mx) mx = cnt, pt = v;
    for (pii u : G[v]){
        if (u.first == p) continue;
        dfs(u.first, v, cnt + u.second);
    }
}

void solve()
{
    fill(G, G + 200005, vector<pii>());
    int i, a, b, c;
    for (i = 1; i <= n - 1; i++){
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    mx = -1, pt = -1;
    dfs(1, -1, 0);
    int from = pt;
    mx = -1, pt = -1;
    dfs(from, -1, 0);
    cout << mx << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n) {
        if (!n) break;
        solve();
    }
    
    return 0;
}