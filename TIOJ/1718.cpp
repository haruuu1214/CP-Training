// #pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
// #define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << " "; dbg(b...);}
void ent() {cout << "\n";}

const int mod = 998244353;
// const int mod = 1e9 + 7;
// const int INF = 2e9;
const int INF = 1e18;

/// ------- Initialization End -------

const int N = 10005;
int dp[N], ndp[N];

signed main() {
    IO;
    
    int m, n, p;
    cin >> m >> n >> p;
    int a, b;
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= m; k++)
            ndp[k] = dp[k];
        for (int j = 1; j <= p; j++) {
            cin >> a >> b;
            for (int k = 0; k + a <= m; k++)
                ndp[k + a] = max(ndp[k + a], dp[k] + b);
        }
        swap(dp, ndp);
    }
    int ans = 0;
    for (int i = 0; i <= m; i++) ans = max(ans, dp[i]);
    cout << ans << "\n";
    
    return 0;
}