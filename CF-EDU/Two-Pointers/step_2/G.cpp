#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
int seg[4*100005];
int arr[100005];
 
void build(int node, int l, int r)
{
    if (l==r) {
        seg[node]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    seg[node] = __gcd(seg[2*node], seg[2*node+1]);
}
 
int query(int node, int l, int r, int qL, int qR)
{
    if (qL<=l && r<=qR)
        return seg[node];
    int mid=(l+r)/2;
    if (qR<=mid)
        return query(2*node, l, mid, qL, qR);
    else if (mid+1<=qL)
        return query(2*node+1, mid+1, r, qL, qR);
    else
        return __gcd( query(2*node, l, mid, qL, qR), query(2*node+1, mid+1, r, qL, qR));
}
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n,q,i;
    cin >> n;
 
    for (i=1;i<=n;i++)
        cin >> arr[i];
    
    build(1, 1, n);
    
    int l, r=1, ans=1e18;
    int gcd;
    for (l=1;l<=n;l++) {
        if (l > r) r = l;
        gcd = query(1, 1, n, l, r);
        while (r < n && gcd != 1) {
            r++;
            gcd = query(1, 1, n, l, r);
        }
        if (gcd == 1)
            ans = min(ans, r-l+1);
        if (gcd != 1 && r == n)
            break;
    }
    cout << (ans == 1e18 ? -1 : ans) << "\n";
    
    return 0;
}