#include <bits/stdc++.h>
#define int long long
using namespace std;

int fastpow(int a, int b, int _mod) {
    int ans = 1, res = a;
    while (b > 0) {
        if (b & 1) ans = (ans * res) % _mod;
        res = (res * res) % _mod;
        b >>= 1;
    }
    return ans;
}

bool is_prime(int n) {
    if (n <= 4) return n == 2 || n == 3;
    int t = __builtin_ctz(n - 1);
    int m = (n - 1) >> t;
    for (auto x : {2, 7, 61}) {
        if (n == x) return true;
        int z = fastpow(x, m, n);
        if (z == 1 || z == n - 1) continue;
        for (int i = 0; i < t; i++) {
            z = 1LL * z * z % n;
            if (z == 1) return false;
            if (z == n - 1) break;
        }
        if (z != n - 1) return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int l, r;
    while (cin >> l >> r) {
        int cnt = 0;
        for (int i = l; i <= r; i++)
            cnt += is_prime(i);
        cout << cnt << "\n";
    }
    return 0;
}