#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
const int N = 200005;
int dp[30][N];

signed main() {
    IO;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> dp[0][i];
    for (int i = 1; i < 30; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        for (int j = 0; j < 30; j++)
            if (b & (1 << j))
                a = dp[j][a];
        cout << a << "\n";
    }
}