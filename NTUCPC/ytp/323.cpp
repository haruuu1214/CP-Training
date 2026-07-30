#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, x, cnt = 0, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (cnt < x)
            cnt += 1;
        else
            cnt = x;
        ans = max(ans, cnt);
    }
    cout << ans;
}