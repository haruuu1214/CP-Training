// #pragma GCC optimize("Ofast, unroll-loops, O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
#define dout(a...) cout << "[" << #a << "] : ", dbg(a)
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << (sizeof...(b) ? ", " : " "); dbg(b...);}
void ent() {cout << "\n";}

const int mod = 998244353;
// const int mod = 1e9 + 7;
const int INF = 1e18;

/// ------- Initialization End -------

const int N = 1000005;
int dp[N];

void solve() {
    int n;
    cin >> n;
    cout << dp[n] << "\n";
}

signed main() {
    IO;
    
    int pre = 0, sum = 1;
    dp[0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        pre = (pre + sum) % mod;
        dp[i] = pre;
        sum += dp[i];
    }

    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}