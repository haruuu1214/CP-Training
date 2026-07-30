#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define siz(x) (int)x.size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// ---------------------------------------------

const int N = 17;
const int mod = 998244353;
int a[N], cost[1 << N];
int two[1 << N];

signed main() {
    IO;
    fill(two, two + (1 << N), INT_MAX);
    int n;
    cin >> n;
    FOR (i, 0, n - 1) cin >> a[i];
    FOR (msk, 0, (1 << n) - 1) {
        int res = 0;
        FOR (i, 0, n - 1)
            if ((msk >> i) & 1)
                res += a[i];
        cost[msk] = res;
    }
    for (int msk = 0; msk < (1 << n); msk++) {
        for (int s = msk; ; s = (s - 1) & msk) {
            two[msk] = min(two[msk], max(cost[s], cost[msk ^ s]));
            if (s == 0) break;
        }
    }
    int ans = INT_MAX;
    for (int msk = 0; msk < (1 << n); msk++)
        ans = min(ans, max(two[msk], two[((1 << n) - 1) ^ msk]));
    cout << ans << "\n";
}