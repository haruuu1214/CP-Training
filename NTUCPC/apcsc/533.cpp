#include <bits/stdc++.h>
#define int unsigned long long
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

signed main() {
    IO;
    int n, x, mx = 0, smx = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > mx) {
            smx = mx;
            mx = x;
        } else if (x > smx) {
            smx = x;
        }
    }
    cout << smx << '\n';
}