#include <bits/stdc++.h>
#define int long long

using namespace std;

string t, p;
int psz, tsz;
int arr[200005];
bool del[200005];

bool able(int m)
{
    fill(del, del+200005, 0);
    for (int i=1;i<=m;i++)
        del[ arr[i] ]=1;
    
    int idx=0;  
    for (int i=0;i<tsz;i++) {
        if (del[i]==1)
            continue;
        if (idx==psz)
            return 1;
        
        if (t[i]==p[idx])
            idx++;
    }
    if (idx==psz) return 1;
    return 0;
}

signed main()
{
    getline(cin, t);
    getline(cin, p);
    tsz=t.size();
    psz=p.size();

    int i;

    int l=1, r=tsz;

    for (i=1;i<=r;i++) {
        cin >> arr[i];
        arr[i]--;
    }

    while (l<=r) {
        int mid=(l+r)/2;

        if (able(mid))
            l=mid+1;
        else
            r=mid-1;
    }

    cout << r << "\n";
    return 0;
}