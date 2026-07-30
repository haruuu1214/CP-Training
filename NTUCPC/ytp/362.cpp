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
    int y = 0, t = 0, p = 0;
    string s;
    while (getline(cin, s)) {
        for (char c : s) {
            if (c == 'y' || c == 'Y') y += 1;
            if (c == 't' || c == 'T') t += 1;
            if (c == 'p' || c == 'P') p += 1;
        }
    }
    cout << min({y, t, p});
}