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

const int mod = 998244353;

signed main() {
    IO;
    int n, cnt = 0;
    string s;
    cin >> n >> s;
    sort(all(s));
    do {
        bool fg = true;
        FOR (i, 0, n - 2)
            if (s[i] == s[i + 1]) {
                fg = false;
                break;
            }
        cnt += fg;
    } while (next_permutation(all(s)));
    cout << cnt;
}