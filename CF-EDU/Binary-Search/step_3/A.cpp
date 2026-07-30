#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>

using namespace std;

int n;
double x[100005], v[100005];

bool check(double t)
{
    int i;
    double l=-1e12, r=1e12;
    for (i=1;i<=n;i++) {
        l=max(l, x[i] - t*v[i]);
        r=min(r, x[i] + t*v[i]);
    }
    return (r-l > 0 ? true : false);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i;
    cin >> n;
    for (i=1;i<=n;i++)
        cin >> x[i] >> v[i];
    
    double l=0, r=1e10;
    while (abs(l-r) >= 0.000001) {
        double mid=(l+r)/2;
        if (check(mid))
            r=mid;
        else
            l=mid;
    }
    cout << setprecision(8) << l << "\n";
    
    return 0;
}