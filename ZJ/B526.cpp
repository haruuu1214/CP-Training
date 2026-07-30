#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    set<int> s;
    int l, r, idx;
    while (q--) {
        cin >> l >> r;
        idx = l;
        if (s.find(idx) != s.end()) {
            s.erase(s.find(idx));
        } else {
            s.insert(idx);
        }

        idx = r + 1;

        if (r + 1 > n)
            continue;

        if (s.find(idx) != s.end()) {
            s.erase(s.find(idx));
        } else {
            s.insert(idx);
        }
    }

    int pre = 1;
    int cnt = 0;
    for (auto i : s) {
        if (pre == -1) {
            pre = i;
        } else {
            cnt += i - pre;
            pre = -1;
        }
    }

    if (pre != -1)
        cnt += n + 1 - pre;

    cout << cnt << "\n";

    return 0;
}