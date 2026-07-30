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
    int n, m;
    cin >> n >> m; cin.ignore();
    vector<string> v(n);
    for (int i = 0; i < n; i++) getline(cin, v[i]);
    int ans = 0;
    for (int j = 0; j < m; j++) {
        bool cur = false;
        for (int i = 0; i < n; i++) {
            if (v[i][j] == 'X') cur = true;
            else {
                if (cur) ans += 1;
                cur = false;
            }
        }
        ans += cur;
    }
    cout << ans;
}