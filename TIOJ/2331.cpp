#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

int n;
vector<int> v;

int count(int k)  /// 計算 >= k 的個數
{
    int l, r = n - 1, cnt = 0;
    for (l = 0; l < n - 1; l++) {
        r = max(r, l + 1);
        while (l < r && v[l] + v[r] >= k)
            r--;
        cnt += n - 1 - r;
    }
    return cnt;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, i, tmp;
    cin >> n >> k;
    for (i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    int l = -2e9 - 10, r = 2e9 + 10;
    while (l < r) {
        int mid = (l + r) >> 1;
        int half = (mid > 0 ? (mid + 1) / 2 : mid / 2);
        int cnt1 = n - (lower_bound(v.begin(), v.end(), half) - v.begin());
        int cnt2 = count(mid);
        if (cnt1 + cnt2 >= k)
            l = mid + 1;
        else
            r = mid;
    }

    l--;

    if (l % 2 == 0)
        cout << l / 2 << "\n" << 1 << "\n";
    else
        cout << l << "\n" << 2 << "\n";

    return 0;
}