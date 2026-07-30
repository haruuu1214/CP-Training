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
const int mod = 1e9 + 7;

struct BIT {
    vector<int> bit;
    int n;
    BIT(int _n) : n(_n), bit(_n + 1) {}
    void update(int id, int va) {
        for (int i = id; i <= n; i += i & -i)
            bit[i] = (bit[i] + va) % mod;
    }
    int query(int id) {
        int sum = 0;
        for (int i = id; i > 0; i -= i & -i)
            sum = (sum + bit[i]) % mod;
        return sum;
    }
};
int a[N];
vector<int> num;

int getl(int x) {
    return lower_bound(all(num), x) - num.begin() + 1;
}

int getr(int x) {
    return upper_bound(all(num), x) - num.begin();
}

signed main() {
    IO;
    int n;
    cin >> n;
    FOR (i, 1, n) {
        cin >> a[i];
        num.push_back(a[i]);
    }
    BIT bit(n);
    sort(all(num)); num.resize(unique(all(num)) - num.begin());
    int ans = 0;
    FOR (i, 1, n) {
        int res = (bit.query(getr(a[i] + 2)) - bit.query(getl(a[i] - 2) - 1) + 1) % mod;
        bit.update(getl(a[i]), res);
        ans += res;
        ans %= mod;
    }
    cout << (ans + mod) % mod;
}