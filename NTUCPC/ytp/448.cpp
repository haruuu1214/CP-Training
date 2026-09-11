#include <bits/stdc++.h>
#define int long long
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int INF = 1e18;
int c[20][20];
int dp[1 << 18];

signed main() {
    IO;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> c[i][j];

    for (int i = 0; i < (1 << 18); i++) dp[i] = INF;
    dp[0] = 0;
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                dp[i | (1 << j) | (1 << k)] = min(dp[i | (1 << j) | (1 << k)], dp[i] + c[j][k]);

    cout << dp[(1 << n) - 1] << "\n";
}