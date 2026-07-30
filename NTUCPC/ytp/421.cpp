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
    auto solve = [&]() {
        string s; int k;
        cin >> s >> k;
        int n = siz(s);
        vector<bool> v(n);
        v[0] = (s[0] == 'X');
        for (int i = 1; i < n; i++) v[i] = (s[i] != s[i - 1]);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (v[i]) {
                if (i + k - 1 < n) {
                    v[i] = 0;
                    if (i + k < n) v[i + k] = !v[i + k];
                    cnt += 1;
                } else {
                    cout << -1 << "\n";
                    return;
                }
            }
        }
        cout << cnt << "\n";
    };
    int t;
    cin >> t;
    while (t--) solve();
}