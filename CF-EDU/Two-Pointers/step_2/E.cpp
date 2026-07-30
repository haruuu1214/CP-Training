#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int arr[100005];
int cnt[100005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, i;
    cin >> n >> k;
    for (i=1;i<=n;i++)
        cin >> arr[i];
    
    set <int> s;
    int l=1, r, sz=0, ans=0;
    for (r=1;r<=n;r++) {
        s.insert(arr[r]);
        cnt[ arr[r] ]++;
        if (cnt[ arr[r] ] == 1)
            sz++;
        while (l <= r && sz > k) {
            cnt[ arr[l] ]--;
            if (cnt[ arr[l] ] == 0) {
                s.erase(s.find(arr[l]));
                sz--;
            }
            l++;
        }
        ans += r-l+1;
    }
    cout << ans << "\n";

    return 0;
}