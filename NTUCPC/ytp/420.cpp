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

const int N = 27;
const int mod = 998244353;

vector<int> G[N];
bool vis[N][N];

void dfs(int v, int cur) {
    vis[cur][v] = true;
    for (int u : G[v]) {
        if (! vis[cur][u])
            dfs(u, cur);
    }
}

signed main() {
    IO;
    string s;
    cin >> s;
    int id = 0;
    for (int i = 0; i < 26; i++) {
        while (id < siz(s) && s[id] != ',') {
            G[s[id] - 'A'].push_back(i);
            // cout << s[id] - 'A' << " " << i << "\n";
            id += 1;
        }
        id += 1;
    }
    string t;
    cin >> t;
    for (int i = 0; i < siz(t); i++) dfs(t[i] - 'A', i);

    for (int i = 0; i < siz(t); i++) {
        string ans;
        for (int j = 0; j < 26; j++)
            if (vis[i][j])
                ans += (char)('A' + j);
        cout << ans << "\n";
    }
}