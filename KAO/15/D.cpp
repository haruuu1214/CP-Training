#pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
// #define int long long
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

/// ------- Initialization End -------

const int N = 1000005;
int a[N];

signed main() {
    IO;
    
    int n, t;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        a[t] = i;
    }
    int cnt = 0;
    for (int i = 1; i <= n - 1; i++) {
        if (cnt & 1) {
            if (a[i] < a[i + 1])
                cnt++;
        } else {
            if (a[i] > a[i + 1])
                cnt++;
        }
    }
    cout << cnt << "\n";
    
    return 0;
}