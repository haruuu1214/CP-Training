#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

bool m[20][20];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, i, j, k;
    cin >> n;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> m[i][j];

    bool flag;
    int mask = 0, cnt, mx = -1;

    for (mask = 0; mask < (1 << n); mask++) {
        flag = true;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i == j || !(mask & (1 << i)) || !(mask & (1 << j)))
                    continue;
                if (m[i][j]) {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }

        if (flag) {
            cnt = 0;
            for (k = 0; k < n; k++)
                if (mask & (1 << k))
                    cnt++;
            mx = max(mx, cnt);
        }
    }

    cout << mx << "\n";

    return 0;
}