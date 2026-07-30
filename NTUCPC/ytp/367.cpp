#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
using namespace std;

const int N = 1005;
int v[N], w[N], x[N], s[N];
bool take[N];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, c;
    cin >> n >> m >> c;
    FOR (i, 1, n) cin >> v[i];
    FOR (i, 1, n) cin >> w[i];
    FOR (i, 1, m) cin >> x[i];
    FOR (i, 1, m) cin >> s[i];
    vector<int> dp(c + 1), dp2(c + 1);
    FOR (i, 1, m) {
        vector<int> vec(s[i]);
        for (int &j : vec) cin >> j;
        int total_v = -x[i], total_w = 0;
        for (int j : vec) total_v += v[j], total_w += w[j], take[j] = true;
        for (int j = c; j >= total_v; j--)
            dp2[j] = dp[j - total_v] + total_w;
        for (int k : vec)
            for (int j = c; j >= v[k]; j--)
                dp[j] = max(dp[j], dp[j - v[k]] + w[k]);
        FOR (j, 0, c)
            dp[j] = max(dp[j], dp2[j]);
    }
    for (int k = 1; k <= n; k++)
        if (! take[k])
            for (int j = c; j >= v[k]; j--)
                dp[j] = max(dp[j], dp[j - v[k]] + w[k]);
    cout << dp[c] << "\n";
}