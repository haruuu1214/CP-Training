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

const int N = 100005;

signed main() {
    IO;
    
    int n, m;
    cin >> n >> m;
    priority_queue <int, vector<int>, greater<int>> Q;
    for (int i = 1; i <= m; i++) Q.push(0);
    int t;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        int x = Q.top();
        Q.pop();
        Q.push(x + t);
    }
    int ans = 0;
    while (!Q.empty()) {
        ans = max(ans, Q.top());
        Q.pop();
    }
    cout << ans << "\n";
    
    return 0;
}