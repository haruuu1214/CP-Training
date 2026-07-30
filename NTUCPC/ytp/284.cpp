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

const int N = 200005;
const int mod = 998244353;
int a[N];

signed main() {
    IO;
    int n, l;
    cin >> l >> n;
    FOR (i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    int nxt_put = 15, ans = 0;
    a[n + 1] = l + 1; n += 1;
    FOR (i, 1, n) {
        if (a[i] <= nxt_put)
            nxt_put = a[i] + 15;
        else {
            int lst = a[i] - 15;
            int cnt = (a[i] - nxt_put + 15 - 1) / 15;
            // cout << i << " " << cnt << "\n";
            ans += cnt;
            nxt_put = a[i] + 15;
        }
    }
    cout << ans;
}