#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    long double c;
    cin >> c;
    long double l=1.0, r=10000000000.0;

    int i;
    while ( abs(l-r) > 0.000001 ) {
        double mid=(l+r)/2;
        if (mid*mid + sqrt(mid) < c)
            l=mid;
        else
            r=mid;
    }
    cout << setprecision(10) << l << "\n";

    return 0;
}