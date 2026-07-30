#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

pii arr[55];
int n;

/*
0 1 2 3 4 5
1 2 3 5 6 7
*/

int calc(int x) /// 大於等於 x 的個數
{
    int i, sum = 0;
    for (int i=1; i<=n; i++) {
        if (arr[i].first <= x)
            sum += max(0ll, min(arr[i].second, x) - arr[i].first + 1);
    }
    return sum;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, i, mn, mx;
    cin >> n >> k;
    for (i=1; i<=n; i++) {
        cin >> arr[i].first >> arr[i].second;
        mn = min(mn, arr[i].first);
        mx = max(mx, arr[i].second);
    }

    int l=mn, r=mx;

    k++;

    while (l <= r) {
        int mid = (l+r)/2;
        if (calc(mid) < k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << l << "\n";

    return 0;
}