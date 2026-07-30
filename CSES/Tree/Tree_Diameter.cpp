// CSES Tree Diameter
// 樹直徑 兩次 DFS 作法
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

vector<int> G[200005];
int mx = -1, pt = -1;

void dfs(int v, int p, int cnt)
{
    if (cnt > mx) mx = cnt, pt = v;
    for (int u:G[v]){
        if (u == p) continue;
        dfs(u, v, cnt+1);
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, i;
    cin >> n;
    int a, b;

    for (i=1; i<=n-1; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    mx = -1, pt = -1;
    dfs(1, -1, 0);

    int from = pt;
    mx = -1, pt = -1;
    dfs(from, -1, 0);
    int to = pt;
    cout << mx << "\n";
    
    return 0;
}