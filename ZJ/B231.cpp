#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

pii arr[1005];

bool cmp(pii a, pii b) {
    if (a.second != b.second)
        return a.second > b.second;
    return a.first > b.first;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, i;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> arr[i].first >> arr[i].second;

    sort(arr + 1, arr + n + 1, cmp);
    int ans = 0;
    int t = 0;
    for (i = 1; i <= n; i++) {
        t += arr[i].first;
        ans = max(ans, t + arr[i].second);
    }
    cout << ans << "\n";

    return 0;
}