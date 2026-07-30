#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

vector<pii> player[55];
int dp[55][10005];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, p, i, j, k, a, b;

    cin >> m >> n >> p;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= p; j++) {
            cin >> a >> b;
            player[i].push_back({a, b});
        }
    }

    int ans = 0;
    for (i = 1; i <= n; i++) {
        for (k = 1; k <= 10000; k++)
            dp[i][k] = dp[i - 1][k];
        for (j = 0; j < p; j++) {
            pii now = player[i][j];
            dp[i][0] = 0;
            for (k = 10000; k >= 1; k--) {
                if (k - now.first >= 0)
                    dp[i][k] = max(dp[i][k], dp[i - 1][k - now.first] + now.second);
                if (k <= m)
                    ans = max(ans, dp[i][k]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}