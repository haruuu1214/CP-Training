#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int arr[100005];
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    int i;
    for (i=1;i<=n;i++)
        cin >> arr[i];
 
    int tmp;
    while (q--) {
        cin >> tmp;
        int L=1, R=n;
        while (L<=R) {
            int mid=(L+R)/2;
            if (arr[mid]<=tmp)
                L=mid+1;
            else
                R=mid-1;
        }
        cout << R << "\n";
    }
    return 0;
}