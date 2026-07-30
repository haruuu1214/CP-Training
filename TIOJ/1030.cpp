// #pragma GCC optimize("Ofast, unroll-loops, O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
using namespace std;
#define dout(a...) cerr << "[" << #a << "] : ", dbg(a)
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << (sizeof...(b) ? ", " : " "); dbg(b...);}
void ent() {cout << "\n";}

const int mod = 998244353;
// const int mod = 1e9 + 7;
const int INF = 1e18;

/// ------- Initialization End -------

const int N = 100005;

signed main() {
    IO;
    
    int n;
    while (cin >> n) {
        if (! n) break;
        vector<int> v(n);
        FOR (i, 0, n - 1) cin >> v[i];
        sort(v.begin(), v.end());
        int ans = v[0] + v[n - 1];
        FOR (i, 0, n - 2) ans += max(v[i], v[i + 1]);
        cout << ans + 1 << "\n";
    }
    
    return 0;
}