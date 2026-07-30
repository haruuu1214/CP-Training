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

const int mod = 998244353;

signed main() {
    IO;
    int n;
    cin >> n;
    int l = 0, r = 1000000;
    while (l + 1 < r) {
        int mid = (l + r + 1) >> 1;
        if (mid * (mid + 1) / 2 <= n)
            l = mid;
        else
            r = mid;
    }
    cout << l << "\n";
}