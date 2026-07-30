// #pragma GCC optimize("Ofast, unroll-loops, O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
using namespace std;
void dout() {;}
template<class T, class ...U>
void dout(T a, U ...b) {cout << a << (sizeof...(b) ? ", " : " "); dout(b...);}
void entr() {cout << "\n";}

const int mod = 998244353;
// const int mod = 1e9 + 7;
const int INF = 1e18;
/// ------- Initialization End -------

const int N = 100005;

signed main() {
    IO;
    
    int n, m;
    cin >> n >> m;
    if (n % 2 == 1) {
        cout << n << "\n";
        for (int i = 1; i <= n; i++)
            cout << i << " " << 1 << "\n";
    } else if (m % 2 == 1) {
        cout << m << "\n";
        for (int i = 1; i <= m; i++)
            cout << 1 << " " << i << "\n";
    } else {
        cout << n * m << "\n";
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cout << i << " " << j << "\n";
    }
    
    return 0;
}