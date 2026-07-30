#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    int n;
    double k;
    cin >> n >> k;
    int i;
    double arr[10005];
    for (i=1;i<=n;i++)
        cin >> arr[i];
    
    double l=0, r=100000000;

    while ( abs(l-r)>=1e-7 ) {
        double mid=(l+r)/2;
        
        int cnt=0;
        for (i=1;i<=n;i++)
            cnt+=arr[i]/mid;
        
        if (cnt>=k)
            l=mid;
        else
            r=mid;
    }
    cout << setprecision(10) << l << "\n";
}