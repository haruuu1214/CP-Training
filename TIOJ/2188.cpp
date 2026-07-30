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
    
    string s;
    cin >> s;
    string ans;
    int n = s.size();
    int t = 0;
    for (int i = 0; i < n; i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            t = t * 10 + (s[i] - '0');
        } else {
            if (!t) {
                ans += s[i];
            } else {
                while (t--)
                    ans += s[i];
            }
            t = 0;
        }
    }
    cout << ans << "\n";
    
    return 0;
}