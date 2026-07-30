#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define F first
#define S second
using namespace std;
using pii = pair<int, int>;

const int N = 100005;
vector<pii> G[N];
bool vis[N];
int a[N];
vector<int> ans;

int dfs(int v) {
    int cnt = (a[v] == 1);
    vis[v] = true;
    for (pii u : G[v]) {
        if (! vis[u.F]) {
            int tmp = dfs(u.F);
            cnt += tmp;
            if (tmp % 2 == 1)
                ans.push_back(u.S);
        }
    }
    return cnt;
}

bool check(int n) {
    for (int i = 1; i <= n; i++) {
        if (! vis[i]) {
            int cnt = dfs(i);
            if (cnt % 2 == 1)
                return false;
        }
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, v, u;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++) {
        cin >> v >> u;
        G[v].push_back({u, i});
        G[u].push_back({v, i});
    }
    if (! check(n)) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " ";
    cout << "\n";
}
