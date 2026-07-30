#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mid (l + r) / 2
#define lc 2 * node
#define rc 2 * node + 1
using namespace std;

int seg[4*1000005], arr[1000005];

void build(int node, int l, int r)
{
    if (l == r) {
        seg[node] = arr[l];
        return;
    }
    build(lc, l, mid);
    build(rc, mid+1, r);
    seg[node] = min(seg[lc], seg[rc]);
}

int query(int node, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
        return seg[node];
    
    if (qr <= mid)
        return query(lc, l, mid, ql, qr);
    else if (mid + 1 <= ql)
        return query(rc, mid + 1, r, ql, qr);
    else
        return min(query(lc, l, mid, ql, qr), query(rc, mid+1, r, ql, qr));
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i=1; i<=n; i++)
        cin >> arr[i];
    
    build(1, 1, n);

    int a, b;
    for (int i=1; i<=n; i++) {
        cin >> a >> b;
        cout << query(1, 1, n, a, b) + 1 << "\n";
    }

    
    return 0;
}