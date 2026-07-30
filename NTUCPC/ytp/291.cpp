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

const int N = 100005, M = 50;
int a[N], val[M], to[M];
int dp1[1 << 22], dp2[1 << 22];

signed main() {
    IO;
    int n, m, k, v, u;
    cin >> n >> m >> k;
    int fir = k / 2;
    int sec = k - k / 2;
    int full = (1ll << k) - 1;
    int fir_full = (1ll << fir) - 1;
    int sec_full = ((1ll << k) - 1) ^ fir_full;
    FOR (i, 1, n) {
        cin >> a[i];
        a[i] -= 1;
    }
    FOR (i, 0, k - 1) to[i] = full;
    FOR (i, 1, m) {
        cin >> v >> u;
        v = a[v]; u = a[u];
        if (v != u) {
            // cout << v << " " << u << "\n";
            to[v] &= (full ^ (1ll << u));
            to[u] &= (full ^ (1ll << v));
        }
    }
    FOR (i, 0, k - 1) cin >> val[i];

    int ans = 0;
    for (int msk = 0; msk < (1 << fir); msk++) {
        bool fail = false;
        for (int i = 0; i < fir; i++) {
            if (msk >> i & 1) {
                if ((msk & (full ^ to[i])) > 0) fail = true;
                dp1[msk] += val[i];
            }
        }
        if (fail) dp1[msk] = 0;
        ans = max(ans, dp1[msk]);
    }
    for (int msk = 0; msk < (1 << fir); msk++) {
        for (int i = 0; i < fir; i++)
            if ((msk >> i & 1) == 0)
                dp1[msk ^ (1 << i)] = max(dp1[msk ^ (1 << i)], dp1[msk]);
    }
    for (int msk = 0; msk < (1 << sec); msk++) {
        int tmp = fir_full;
        bool fail = false;
        for (int i = 0; i < sec; i++) {
            if (msk >> i & 1) {
                if (((msk << fir) & (full ^ to[fir + i])) > 0) fail = true;
                tmp = tmp & to[fir + i];
                dp2[msk] += val[fir + i];
            }
        }
        if (! fail)
            ans = max(ans, dp1[tmp] + dp2[msk]);
    }
    // FOR (i, 0, k - 1) cout << to[i] << " \n"[i == k - 1];
    // cout << fir << " " << sec << "\n";
    cout << ans;
}
/*
2 1 2
1 2
1 2
1 5
*/