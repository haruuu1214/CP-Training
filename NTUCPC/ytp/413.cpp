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

const int N = 500005;
const int mod = 998244353;
int a[N];
bool cnt[N], vis[N];

signed main() {
    IO;
    int n;
    cin >> n;
    bool suc = true;
    FOR (i, 1, n) {
        cin >> a[i];
        cnt[a[i]] = true;
        if (i == a[i]) suc = false;
    }
    FOR (i, 1, n) if (! cnt[i]) suc = false;
    if (! suc) {
        cout << -1;
        return 0;
    }
    int ans = 0;
    FOR (i, 1, n) {
        if (! vis[i]) {
            int cur = i;
            while (! vis[cur]) {
                vis[cur] = true;
                cur = a[cur];
            }
            ans += 1;
        }
    }
    cout << ans;

}