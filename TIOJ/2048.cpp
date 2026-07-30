#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int arr[1000005];
int dp0[1000005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, i;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> arr[i];

    int dp1 = -1e18;
    dp0[0] = -1e18;
    dp0[1] = arr[1];
    for (i = 2; i <= n; i++) {
        dp0[i] = max(dp0[i-1], max(0ll, dp0[i-1]) + arr[i]); /// 前綴 max
        dp1 = max({dp1, dp1 + arr[i], dp0[i-2] + arr[i]});
    }

    cout << dp1 << "\n";

    return 0;
}