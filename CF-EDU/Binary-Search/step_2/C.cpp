#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    int n,x,y;
    cin >> n >> x >> y;
    int tmp;
    if (x>y)
        tmp=x, x=y, y=tmp;

    int l=0, r=100000000000;
    while (l<=r) {
        int mid=(l+r)/2;

        int cnt = mid/x + (mid-x)/y;

        if (cnt>=n)
            r=mid-1;
        else
            l=mid+1;
    }

    cout << l << "\n";
    return 0;
}