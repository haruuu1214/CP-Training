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

const int N = 500005;
const int mod = 998244353;

struct BIT {
    vector<int> bit;
    int n;
    BIT(int _n) : n(_n), bit(_n + 1) {}
    void update(int id, int va) {
        for (int i = id; i <= n; i += i & -i)
            bit[i] = max(bit[i], va);
    }
    int query(int id) {
        int sum = 0;
        for (int i = id; i > 0; i -= i & -i)
            sum = max(sum, bit[i]);
        return sum;
    }
};

pair<pii, int> a[N];

signed main() {
    IO;
    int n;
    cin >> n;
    FOR (i, 1, n) {
        cin >> a[i].F.F >> a[i].F.S >> a[i].S;
        a[i].F.F++;
        a[i].F.S++;
    }
    sort(a + 1, a + n + 1);
    BIT bit(500005);
    int ans = 0;
    FOR (i, 1, n) {
        int res = bit.query(a[i].F.F);
        res += a[i].S;
        ans = max(ans, res);
        bit.update(a[i].F.S, res);
    }
    cout << ans << "\n";
}