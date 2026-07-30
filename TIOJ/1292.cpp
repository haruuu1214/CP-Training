#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

vector <int> G[10005];
int cnt;

bool dfs(int v, int p)
{
    bool be_cut = 0;
    for (auto u : G[v]) {
        if (u != p && !dfs(u, v)) {
            be_cut = 1;
        }
    }
    if (be_cut) cnt++;
    return be_cut;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, i, n;
    cin >> n;
    for (i = 1; i <= n - 1; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    cnt = 0;
    dfs(1, 1);
    cout << cnt << "\n";
    return 0;
}