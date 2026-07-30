#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int a[100005], b[100005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i, j;
    cin >> n >> m;
    for (i=1;i<=n;i++)
        cin >> a[i];
    for (i=1;i<=m;i++)
        cin >> b[i];

    int p, q, ans = 0;
    p=1, q=1;
    while (p<=n && q<=m) {
        if (a[p] > b[q])
            q++;
        else if (a[p] < b[q])
            p++;
        else {
            int acnt = upper_bound(a+1, a+n+1, a[p]) - lower_bound(a+1, a+n+1, a[p]);
            int bcnt = upper_bound(b+1, b+m+1, b[q]) - lower_bound(b+1, b+m+1, b[q]);
            ans += acnt * bcnt;

            p += acnt;
            q += bcnt;
        }
    }
    cout << ans << "\n";
    
    return 0;
}