#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define siz(x) (int)x.size()
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// ---------------------------------------------

const int N = 500005;
const int mod = 998244353;
vector<int> G[N];
bool pass[N];
int mx_len, pt;

void dfs(int v, int p, int dis) {
    if (dis > mx_len) {
        mx_len = dis;
        pt = v;
    }
    for (int u : G[v]) {
        if (u != p)
            dfs(u, v, dis + 1);
    }
}

bool dfs_color(int v, int p, int dis) {
    if (dis == mx_len) {
        pass[v] = true;
        return true;
    }
    bool res = false;
    for (int u : G[v]) {
        if (u != p)
            res |= dfs_color(u, v, dis + 1);
    }
    if (res == true) pass[v] = true;
    return res;
}

void solve() {
    int n, v, u;
    cin >> n;
    FOR (i, 1, n - 1) {
        cin >> v >> u;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    mx_len = pt = 0;
    dfs(1, -1, 0);
    int a = pt;
    mx_len = pt = 0;
    dfs(a, -1, 0);
    int b = pt;

    dfs_color(a, -1, 0);
    dfs_color(b, -1, 0);
    for (int i = 1; i <= n; i++) cout << pass[i] << " \n"[i == n];
    for (int i = 1; i <= n; i++) pass[i] = false;
    for (int i = 1; i <= n; i++) G[i].clear();
}

signed main() {
    IO;
    int t;
    cin >> t;
    while (t--) solve();
}