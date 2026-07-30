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
    
    int p=1, q=1;
    while (p<=n && q<=m) {
        if (a[p]<=b[q]) {
            cout << a[p] << " ";
            p++;
        } else {
            cout << b[q] << " ";
            q++;
        }
    }
    while (p<=n) {
        cout << a[p] << " ";
        p++;
    }
    while (q<=m) {
        cout << b[q] << " ";
        q++;
    }
    cout << "\n";

    return 0;
}