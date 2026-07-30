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

const int N = 100005;
const int mod = 998244353;

signed main() {
    IO;
    int na = 1, nb = 1;
    int n, a, b, ans = 0;
    cin >> n;
    FOR (i, 1, n) {
        cin >> a >> b;
        if (a != 3) {
            if (a != na) {
                na = a;
                ans += 1;
            }
        }
        if (b != 3) {
            if (b != nb) {
                nb = b;
                ans += 1;
            }
        }
    }
    cout << ans;
}