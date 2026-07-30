#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
int a[100005], b[100005];
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n,m,i;
    cin >> n >> m;
    for (i=1;i<=n;i++)
        cin >> a[i];
    for (i=1;i<=m;i++)
        cin >> b[i];
    
    int p=0;
    for (i=1;i<=m;i++) {
        while (p+1<=n) {
            if (a[p+1]>=b[i])
                break;
            p++;
        }
        cout << p << " ";
    }

    cout << "\n";

    return 0;
}