#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int a[N];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    fill(a, a + N, INT_MAX);
    int n, m, x, t;
    cin >> m >> n;
    while (m--) {
        cin >> x >> t;
        for (int i = x; i <= n; i++)
            a[i] = min(a[i], t + i - x);
        for (int i = x; i >= 1; i--)
            a[i] = min(a[i], t + x - i);
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
}