#pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    int a[105] = {0};
    a[0] = 1;
    for (int i = 0; i < n; i++) {
        a[i + 1] += a[i];
        a[i + 2] += a[i];
    }
    cout << a[n] << "\n";
    
    return 0;
}