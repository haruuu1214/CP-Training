#include <bits/stdc++.h>
#define int long long
#define mid ((l + r) >> 1)
#define lc (node << 1)
#define rc ((node << 1) | 1)
using namespace std;

int seg[2][4 * 100005];
int arr[100005];
int input[100005];

void build(int tr, int node, int l, int r)
{
    if (l == r) {
        seg[tr][node] = arr[l];
        return;
    }
    build(tr, lc, l, mid);
    build(tr, rc, mid + 1, r);
    seg[tr][node] = seg[tr][lc] + seg[tr][rc];
}

void update(int tr, int node, int l, int r, int idx, int val)
{
    if (l == r) {
        seg[tr][node] = val;
        return;
    }
    if (idx <= mid)
        update(tr, lc, l, mid, idx, val);
    else
        update(tr, rc, mid + 1, r, idx, val);
    seg[tr][node] = seg[tr][lc] + seg[tr][rc];
}

int query(int tr, int node, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
        return seg[tr][node];
    if (qr <= mid)
        return query(tr, lc, l, mid, ql, qr);
    else if (mid+1<=ql)
        return query(tr, rc, mid + 1, r, ql, qr);
    else
        return query(tr, lc, l, mid, ql, qr) + query(tr, rc, mid + 1, r, ql, qr);
}

signed main()
{
    int n, q;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> input[i];
    
    /// odd
    for (int i = 1; i <= n; i++)
        arr[i] = (i % 2 == 1 ? input[i] : 0);
    build(0, 1, 1, n);

    /// even
    for (int i = 1; i <= n; i++)
        arr[i] = (i % 2 == 0 ? input[i] : 0);
    build(1, 1, 1, n);

    cin >> q;
    
    int v, x, k, l, r;
    while (q--) {
        cin >> v;
        if (v == 0) {
            cin >> x >> k;
            if (x % 2 == 1)
                update(0, 1, 1, n, x, k);
            else
                update(1, 1, 1, n, x, k);
        } else {
            cin >> l >> r;
            int ans;
            if (l % 2 == 1)
                ans = query(0, 1, 1, n, l, r) - query(1, 1, 1, n, l, r);
            else
                ans = query(1, 1, 1, n, l, r) - query(0, 1, 1, n, l, r);
            cout << ans << "\n";
        }
    }
    
    return 0;
}

