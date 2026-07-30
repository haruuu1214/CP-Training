#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int n, k;
int arr[10005];

bool check(int x) /// 間隔 x 是否可行
{
    int mx = arr[n];
    int idx;
    int now = arr[1];
    for (int i=2; i<=k; i++) {
        idx = lower_bound(arr+1, arr+n+1, now + x) - (arr);
        if (idx > n)
            return true;
        else
            now = arr[idx];
    }
    return false;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i=1; i<=n; i++)
        cin >> arr[i];
/*
    for (int i=1; i<=15; i++)
        cout << check(i) << " ";
*/
    int l = 0, r = 1e9;
    while (l <= r) {
        int mid = (l+r) / 2;
        if (check(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << r << "\n";

    return 0;
}