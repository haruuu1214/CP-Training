#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define siz(x) (int)x.size()
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// ---------------------------------------------

const int N = 10005;
const int mod = 998244353;
int a[N], b[N];

signed main() {
    IO;
    int n, m, t;
    cin >> n >> m >> t;
    int head = 0, tail = n - 1;
    FOR (i, 0, n - 1) cin >> a[i];
    FOR (i, 0, t - 1) cin >> b[i];
    int pos = 0, ans = 0;
    FOR (i, 0, t - 1) {
        ans += 1;
        pos += b[i];
        if (pos > tail) break;
        pos += a[pos];
        if (pos == tail) break;
        head += m; tail -= m;
        if (pos < head || tail < pos) break;
    }
    if (pos == tail)
        cout << "Winner Penguin\n";
    else
        cout << "Dumb Dumb Penguin\n";
    cout << "Survived " << ans << " rounds\n";
}