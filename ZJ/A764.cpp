#include <bits/stdc++.h>
#define int long long
using namespace std;
int dis[1005][1005], edge[1005][1005];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(&edge[0][0], &edge[0][0] + 1005 * 1005, 1e18);
    fill(&dis[0][0], &dis[0][0] + 1005 * 1005, 1e18);

    int n, m, i, j, k;
    cin >> n >> m;

    int a, b, c;
    for (i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        edge[a][b] = edge[b][a] = min(edge[a][b], c);
        dis[a][b] = dis[b][a] = edge[a][b];
    }

    int ans = 1e18;

    for (k = 1; k <= n; k++) {
        for (i = 1; i < k; i++) {
            for (j = i + 1; j < k; j++) {
                ans = min(ans, edge[k][i] + edge[k][j] + dis[i][j]);
            }
        }

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    if (ans == 1e18)
        cout << "No solution.\n";
    else
        cout << ans << "\n";

    return 0;
}
/*

5 6
1 2 1
1 3 100
1 4 1
2 3 1
3 5 1
4 5 1

*/