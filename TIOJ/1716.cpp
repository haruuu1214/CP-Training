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
    
    int t;
    cin >> t;
    int a, b, c;
    while (t--) {
        cin >> a >> b >> c;
        if (b * b - 4 * a * c >= 0) {
            int x = b * b - 4 * a * c;
            int sq = sqrt(x);
            if (sq * sq == x)
                cout << "Yes\n";
            else
                cout << "No\n";
        } else {
            cout << "No\n";
        }
    }
    
    return 0;
}