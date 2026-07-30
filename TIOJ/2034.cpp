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
    
    int n;
    cin >> n;
    vector <int> v(n);
    for (int i = 0; i < v.size(); i++) cin >> v[i];
    sort(v.begin(), v.end());
    int mn = INF, mx = -INF;
    for (int i : v) {
        mn = min(mn, i);
        mx = max(mx, i);
    }
    
    cout << mn << " " << mx << " " << (mx - mn + 1 == n ? "yes\n" : "no\n");

    return 0;
}