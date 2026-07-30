#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int n;
int calc(int x)
{
    int sum = 0;
    for (int i=1; i<=n; i++) {
        int tmp = x/i;
        sum += min(tmp, n);
    }
    return sum;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> n >> k;
/*
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++)
            cout << i*j << " ";
        cout << "\n";
    }
*/
/*
    for (int i=1; i<=n*n; i++)
        cout << i << " " << calc(i) << "\n";
*/
    int l = 1, r = n*n - 1; 
    while (l <= r) {
        int mid = (l+r) / 2;
        // cout << l << " " << mid << " " << r << "\n";
        if (calc(mid) < k)
            l = mid + 1;
        else    
            r = mid - 1;
        
    }
    cout << l << "\n";
    return 0;
}