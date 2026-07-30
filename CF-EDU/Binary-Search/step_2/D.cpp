/**
 * @brief 對答案二分搜
 *        a ---> 充一顆氣球的時間
 *        b ---> 充 ? 顆會累 需要休息
 *        c ---> 休息時間
 * 
 */
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int m, n;
int a[1005], b[1005], c[1005];

bool check(int t)
{
    int i, sum = 0;
    for (i=1;i<=n;i++) {
        int cnt = (t / (a[i] * b[i] + c[i])) * b[i];
        int remaintime = t % (a[i] * b[i] + c[i]);
        int addcnt = remaintime / a[i];
        addcnt = (addcnt >= b[i] ? b[i] : addcnt);
        sum += cnt + addcnt;
    }
    if (sum >= m) return true;
    return false;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i;
    cin >> m >> n;
    for (i=1;i<=n;i++)
        cin >> a[i] >> b[i] >> c[i];
    
    int l=0, r=1e9;
    while (l <= r) {
        int mid = (l+r)/2;
        if (check(mid))
            r=mid-1;
        else
            l=mid+1;
    }
    
    int ans = l;
    cout << ans << "\n";

    int arr[1005];

    for (i=1;i<=n;i++) {
        int cnt = (ans / (a[i] * b[i] + c[i])) * b[i];
        int remaintime = ans % (a[i] * b[i] + c[i]);
        int addcnt = remaintime / a[i];
        addcnt = (addcnt >= b[i] ? b[i] : addcnt);
        arr[i] = cnt + addcnt;
    }
    int sum = 0;
    for (i=1;i<=n;i++) {
        if (sum >= m)
            cout << 0 << " ";
        else if (sum + arr[i] > m)
            cout << m-sum << " ";
        else
            cout << arr[i] << " ";
        sum += arr[i];
    }
    cout << "\n";
    
    return 0;
}