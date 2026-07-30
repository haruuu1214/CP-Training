#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int arr[100005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, i;
    cin >> n >> k;
    
    for (i=1;i<=n;i++)
        cin >> arr[i];
    int l=1, r, sum=0, ans=1e9;
    for (r=1;r<=n;r++) {
        sum += arr[r];
        while (l <= r && sum - arr[l] >= k) {
            sum -= arr[l];
            l++;
        }
        if (sum >= k)
            ans = min(ans, r-l+1);
    }
    cout << (ans == 1e9 ? -1 : ans) << "\n";

    return 0;
}