#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

int dp[105][105][105];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    for (int i = 1; i <= (int)a.size(); i++) {
        for (int j = 1; j <= (int)b.size(); j++) {
            for (int k = 1; k <= (int)c.size(); k++) {
                if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else {
                    dp[i][j][k] = max({dp[i - 1][j][k],
                                       dp[i][j - 1][k],
                                       dp[i][j][k - 1]});
                }
            }
        }
    }

    cout << dp[(int)a.size()][(int)b.size()][(int)c.size()] << "\n";

    return 0;
}