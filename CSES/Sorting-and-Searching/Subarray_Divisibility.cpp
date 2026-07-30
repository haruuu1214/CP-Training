#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

const int N = 200005;
int a[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, pre = 0;
    cin >> n;
    a[pre] += 1;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        pre += x;
        pre = (pre % n + n) % n;
        a[pre] += 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += a[i] * (a[i] - 1) / 2;
    cout << ans << "\n";

    return 0;
}