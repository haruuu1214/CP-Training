#include <bits/stdc++.h>
#define int long long
using namespace std;

int mul(int a, int b, int _mod) {
    int res = 0;
    while (b > 0) {
        if (b & 1) res = (res + a) % _mod;
        a = (a << 1) % _mod;
        b >>= 1;
    }
    return res;
}

int fastpow(int a, int b, int _mod) {
    int ans = 1, res = a;
    while (b > 0) {
        if (b & 1) ans = mul(ans, res, _mod);
        res = mul(res, res, _mod);
        b >>= 1;
    }
    return ans;
}

bool is_prime(int n) {
    if (n <= 4) return n == 2 || n == 3;
    int t = __builtin_ctz(n - 1);
    int m = (n - 1) >> t;
    // for (auto x : {2, 7, 61})
    for (auto x : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        if (n == x) return true;
        int z = fastpow(x, m, n);
        if (z == 1 || z == n - 1) continue;
        for (int i = 0; i < t; i++) {
            z = mul(z, z, n);
            if (z == 1) return false;
            if (z == n - 1) break;
        }
        if (z != n - 1) return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int x;
    while (cin >> x)
        cout << (is_prime(x) ? "Yes\n" : "No\n");
    
    return 0;
}