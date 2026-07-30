#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, sum = 0;
    cin >> n >> m;
    int x = min(n, m);
    for (int i = 1; i <= x - 1; i++)
        sum += i * i * (n - i) * (m - i);
    for (int i = 1; i <= x; i++)
        for (int j = i; i + j <= x; j++)
            sum += (i != j ? 2ll : 1ll) * (i * i + j * j) * (n - i - j) * (m - i - j);
    cout << sum;
}