#include <bits/stdc++.h>
#define int long long

using namespace std;

int arr[100005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin >> n;
    int i;
    for (i=1;i<=n;i++)
        cin >> arr[i];
    sort(arr+1, arr+n+1);
    cin >> q;
    while (q--) {
        int ql,qr;
        cin >> ql >> qr;

        int l,r;
        l=1, r=n;
        while (l<=r) {
            int mid=(l+r)/2;
            if (arr[mid]>=ql)
                r=mid-1;
            else
                l=mid+1;
        }
        int idx1=r;

        l=1, r=n;
        while (l<=r) {
            int mid=(l+r)/2;
            if (arr[mid]>qr)
                r=mid-1;
            else
                l=mid+1;
        }
        int idx2=r;
        cout << idx2-idx1 << " ";
    }
    cout << "\n";
    


    return 0;
}