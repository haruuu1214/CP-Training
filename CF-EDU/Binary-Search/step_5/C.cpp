#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int n;
int a[100005], b[100005];

int calc(int x) /// ai + bj <= x 的數量
{
    int l, r = n, cnt = 0;
    for (l=1; l<=n; l++) {
        while (r >= 1 && a[l] + b[r] > x)
            r--;
        cnt += r;
    }
    return cnt;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> n >> k;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=n; i++)
        cin >> b[i];
    
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);

    int l = a[1] + b[1], r = a[n] + b[n];
/*
    for (int i=l; i<=r; i++)
        cout << i << " " << calc(i) << "\n";
*/
    while (l <= r) {
        int mid = (l+r) / 2;
        if (calc(mid) < k)
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << l << "\n";
    
    return 0;
}