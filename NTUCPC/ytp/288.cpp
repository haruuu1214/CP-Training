#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define siz(x) (int)x.size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// ---------------------------------------------

const int N = 1;
const int mod = 998244353;

signed main() {
    IO;
    int n;
    cin >> n;
    int xmx = -INT_MAX, ymx = -INT_MAX;
    int xmn = INT_MAX, ymn = INT_MAX;
    int x, y;
    FOR (i, 1, n) {
        cin >> x >> y;
        xmx = max(xmx, x); ymx = max(ymx, y);
        xmn = min(xmn, x); ymn = min(ymn, y);
    }
    int r1 = (xmx - xmn + 1) / 2;
    int r2 = (ymx - ymn + 1) / 2;
    if (r1 == r2) {
        cout << r1 << "\n";
        cout << (xmx + xmn) / 2 << " " << (ymx + ymn) / 2 << "\n";
    } else if (r1 > r2) {
        cout << r1 << "\n";
        cout << (xmx + xmn) / 2 << " " << max(0ll, ymx - r1) << "\n";
    } else {
        cout << r2 << "\n";
        cout << max(0ll, xmx - r2) << " " << (ymx + ymn) / 2 << "\n";
    }
}