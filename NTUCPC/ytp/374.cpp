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

const int N = 200005;
const int p = 1e6 + 3;
const int mod = 1e9 + 7;
int a[N], b[N], pow_p[N], inv_p[N];
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

int fastpow(int a, int b) {
    int ans = 1, res = a;
    while (b > 0) {
        if (b & 1) ans = ans * res % mod;
        res = res * res % mod;
        b >>= 1;
    }
    return ans;
}

signed main() {
    IO;
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    FOR (i, 0, n - 1) {
        a[i + 1] = s[i] - 'a';
        b[n - i] = s[i] - 'a';
    }
    pow_p[0] = 1;
    FOR (i, 1, n)
        pow_p[i] = (pow_p[i - 1] * p) % mod;
    inv_p[1] = fastpow(p, mod - 2);
    FOR (i, 2, n)
        inv_p[i] = inv_p[i - 1] * inv_p[1] % mod;
    BIT bit(n), bit2(n);
    FOR (i, 1, n) {
        bit.update(i, a[i] * pow_p[i]);
        bit2.update(i, b[i] * pow_p[i]);
    }
    int o, id, va, l, r;
    char c;
    while (q--) {
        cin >> o;
        if (o == 0) {
            cin >> id >> c;
            va = c - 'a';
            bit.update(id, (va - a[id]) * pow_p[id]);
            bit2.update(n - id + 1, (va - b[n - id + 1]) * pow_p[n - id + 1]);
            a[id] = b[n - id + 1] = va;
        } else {
            cin >> l >> r;
            int res1 = (bit.query(r) - bit.query(l - 1)) * inv_p[l];
            int res2 = (bit2.query(n - l + 1) - bit2.query(n - r)) * inv_p[n - r + 1];
            res1 = (res1 % mod + mod) % mod;
            res2 = (res2 % mod + mod) % mod;
            cout << (res1 == res2 ? "YES\n" : "NO\n");
        }
    }
}