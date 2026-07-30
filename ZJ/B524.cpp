#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while (getline(cin, s)) {
        int y_idx = 0, cnt = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == 'y') {
                cnt += (i - y_idx > 0 ? i - y_idx : y_idx - i);
                y_idx += 3;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}