#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a, I = b; i <= I; i++)
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
    int x;
    FOR(i, 1, n) {
        cin >> x;
        cout << x << "\n";
    }
    
    return 0;
}