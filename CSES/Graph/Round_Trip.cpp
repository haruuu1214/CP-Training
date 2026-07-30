#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> G[N];
vector<int> cyc;
bool vis[N], suc = false;
stack<int> stk;

void dfs(int v, int p) {
    if (suc) return;
    vis[v] = true;
    stk.push(v);
    for (int u : G[v]) {
        if (u == p) continue;
        if (vis[u] && !suc) {
            suc = true;
            cyc.push_back(u);
            while (!stk.empty() && stk.top() != u) {
                cyc.push_back(stk.top());
                stk.pop();
            }
            cyc.push_back(u);
            return;
        }
        dfs(u, v);
    }
    if (suc) return;
    stk.pop();
}

signed main() {
    int n, m;
    cin >> n >> m;
    int v, u;
    for (int i = 1; i <= m; i++) {
        cin >> v >> u;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        while (!stk.empty()) stk.pop();
        if (!vis[i])
            dfs(i, -1);
        if (suc)
            break;
    }
    if (suc) {
        cout << cyc.size() << "\n";
        for (int i : cyc)
            cout << i << " ";
        cout << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}