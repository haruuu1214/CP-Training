#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, now;
    cin >> n;

    deque<pii> dq;
    ///         idx  val
    dq.push_back({0, -1});

    for (int i = 1; i <= n; i++) {
        cin >> now;
        while (now <= dq.back().second) {
            dq.pop_back();
        }
        cout << dq.back().first << " ";
        dq.push_back({i, now});
    }
    cout << "\n";

    return 0;
}