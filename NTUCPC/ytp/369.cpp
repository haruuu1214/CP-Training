#include <bits/stdc++.h>
#define int long long
#define siz(x) (int)x.size()
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
using namespace std;

const int p = 1e6 + 3;
const int mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, x, y;
    cin >> n >> m;
    vector<string> s(n);
    FOR (i, 0, n - 1) cin >> s[i];
    vector<vector<int>> v(n);
    FOR (i, 0, n - 1) {
        v[i].resize(siz(s[i]));
        v[i][0] = (int)(s[i][0]);
        FOR (j, 1, siz(s[i]) - 1) {
            v[i][j] = v[i][j - 1] * p + (int)(s[i][j]);
            v[i][j] %= mod;
        }
    }
    while (m--) {
        cin >> x >> y;
        int l = -1, r = min(siz(s[x]), siz(s[y]));
        while (l + 1 < r) {
            int mid = (l + r + 1) >> 1;
            if (v[x][mid] == v[y][mid])
                l = mid;
            else
                r = mid;
        }
        cout << l + 1 << '\n';
    }
}