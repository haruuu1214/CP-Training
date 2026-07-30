#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

void solve() {
    int n;
    cin >> n;

    map<int, int> m;
    int tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        m[tmp]++;
    }
    int mx = -1, ans = -1;
    for (auto [a, b] : m) {
        if (b > mx) {
            mx = b;
            ans = a;
        }
    }
    if (mx <= n / 2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--)
        solve();

    return 0;
}