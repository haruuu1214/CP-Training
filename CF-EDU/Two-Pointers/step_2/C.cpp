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
    int l = 1, r, sum = 0, cnt = 0;
    for (r=1;r<=n;r++) {
        sum += arr[r];
        while (sum > k) {
            sum -= arr[l];
            l++;
        }
        cnt += r-l+1;
    }
    cout << cnt << "\n";

    return 0;
}