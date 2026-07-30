#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int arr[100005];

struct point
{
    int mn, mx;
} seg[4*100005];

point combine(point a, point b) {
    point p;
    p.mn = min(a.mn, b.mn);
    p.mx = max(a.mx, b.mx);
    return p;
}

void build(int node, int l, int r)
{
    if (l == r) {
        seg[node].mn = seg[node].mx = arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    seg[node] = combine(seg[2*node], seg[2*node+1]);
}

point query(int node, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
        return seg[node];
    
    int mid=(l+r)/2;
    if (qr <= mid)
        return query(2*node, l, mid, ql, qr);
    else if (mid+1 <= ql)
        return query(2*node+1, mid+1, r, ql, qr);
    else 
        return combine( query(2*node, l, mid, ql, qr), query(2*node+1, mid+1, r, ql, qr) );
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, i;
    cin >> n >> k;
    for (i=1;i<=n;i++)
        cin >> arr[i];
    build(1, 1, n);

    point p;
    int l=1, r, ans=0;
    for (r=1;r<=n;r++) {
        p = query(1, 1, n, l, r);

        while (l <= r && p.mx - p.mn > k) {
            l++;
            p = query(1, 1, n, l, r);
        }

        ans += r-l+1;
    }
    cout << ans << "\n";

    return 0;
}