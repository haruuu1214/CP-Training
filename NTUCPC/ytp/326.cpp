#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

const int N = 2005;
bool vis[N][N];
int dx[6] = {0, 0, 1, -1, 1, -1};
int dy[6] = {1, -1, 0, 0, 1, -1};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    int x = 1000, y = 1000;
    for (char c : s) {
        if (c == 'A') x += 1, y += 1;
        if (c == 'B') x += 1;
        if (c == 'C') y -= 1;
        if (c == 'D') x -= 1, y -= 1;
        if (c == 'E') x -= 1;
        if (c == 'F') y += 1;
        vis[x][y] = true;
    }
    map<pii, int> dis;
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> Q;
    dis[{1000, 1000}] = 0;
    Q.push({0, {1000, 1000}});
    while (! Q.empty()) {
        auto [step, pos] = Q.top(); Q.pop();
        if (dis[{pos.F, pos.S}] != step) continue;
        if (pos.F == x && pos.S == y) {
            cout << step << "\n";
            return 0;
        }
        for (int i = 0; i < 6; i++) {
            int nx = pos.F + dx[i], ny = pos.S + dy[i];
            if (vis[nx][ny] && (dis.count({nx, ny}) == 0 || step + 1 < dis[{nx, ny}])) {
                dis[{nx, ny}] = step + 1;
                Q.push({dis[{nx, ny}], {nx, ny}});
            }
        }
    }
}