#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define siz(x) (int)x.size()
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// ---------------------------------------------

const int mod = 1e9 + 9;

signed main() {
    IO;
    int n;
    cin >> n;
    int lst, cur, ans = 1;
    cin >> lst;
    for (int i = 2; i <= n; i++) {
        cin >> cur;
        ans = ans * (cur - lst) % mod;
        lst = cur;
    }
    cout << (ans + mod) % mod << "\n";
}