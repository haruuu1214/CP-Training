#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define loop(i,a,b) for(int i=a; i<=b; i++)
using namespace std;

int a[100005];
int sz[100005];
vector <pii> G[100005];
int k, ans = 0;

int dfs(int v, int p)
{
    int cnt = 0;
    sz[v] = 1;
    for (auto [u, cost] : G[v]) {
        if (u == p) continue;
        int tmp = dfs(u, v);
        ans += (tmp > 0 ? tmp * cost : -tmp * cost);
        cnt += tmp;
        sz[v] += sz[u];
    }
    cnt += a[v] - k;
    return cnt;
}


signed main()
{
    IOS

    int n;
    cin >> n >> k;
    loop(i, 1, n)
        cin >> a[i];
    
    int a, b, c;
    loop(i, 1, n - 1) {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    dfs(1, -1);
    
    cout << ans << "\n";
    
    return 0;
}