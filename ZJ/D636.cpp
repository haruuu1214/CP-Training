/*

a ^ b = ( (a % 10007) ^ (b % 10006) ) % 10007    ( MOD 10007 )

*/
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

int fastpow(int a, int b) {
    int res = a, ans = 1;
    while (b > 0) {
        if (b & 1)
            ans = (ans * res) % 10007;
        res = (res * res) % 10007;
        b >>= 1;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    a %= 10007;
    b %= 10006;

    cout << fastpow(a, b) << "\n";

    return 0;
}