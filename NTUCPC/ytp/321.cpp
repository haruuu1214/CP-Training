#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    auto solve = [&]() {
        int n, m, x[4], y[4];
        cin >> n >> m;
        for (int i = 0; i < 4; i++) cin >> x[i] >> y[i];
        if (x[0] > x[1]) swap(x[0], x[1]), swap(y[0], y[1]);
        if (x[2] > x[3]) swap(x[2], x[3]), swap(y[2], y[3]);
        bool fg = ((y[0] <= y[1] && y[2] <= y[3]) || (y[0] >= y[1] && y[2] >= y[3]));
        int dx = min(x[1], x[3]) - max(x[0], x[2]);
        if (y[0] > y[1]) swap(y[0], y[1]);
        if (y[2] > y[3]) swap(y[2], y[3]);
        int dy = min(y[1], y[3]) - max(y[0], y[2]);
        if (dx < 0 || dy < 0)
            cout << 0 << "\n";
        else if (fg)
            cout << dx + dy + 1 << "\n";
        else
            cout << max(dx, dy) + 1 << "\n";
    };
    int t;
    cin >> t;
    while (t--) solve();
}