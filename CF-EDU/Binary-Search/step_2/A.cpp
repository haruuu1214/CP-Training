#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    int w,h,n;
    cin >> w >> h >> n;

    int l=1, r=2;
    while ( (r/w)*(r/h) < n ) r*=2;

    while (l<=r) {
        int mid=(l+r)/2;
        int tmp=(mid/w)*(mid/h);
        if (tmp>=n)
            r=mid-1;
        else
            l=mid+1;
    }
    cout << l << "\n";

    return 0;
}