#include <bits/stdc++.h>
#define int long long
#define mid ((l + r) >> 1)
#define lc (node << 1)
#define rc ((node << 1) | 1)
using namespace std;

int seg[4 * 200005];
int tag[4 * 200005];

void push(int node, int l, int r)
{
    if (tag[node] != 0) {
        tag[lc] += tag[node];
        tag[rc] += tag[node];
        seg[lc] += (mid - l + 1) * tag[node];
        seg[rc] += (r - (mid + 1) + 1) * tag[node];
        tag[node] = 0;
    }
}

void update(int node, int l, int r, int ql, int qr, int val)
{
    if (ql <= l && r <= qr) {
        seg[node] += val * (r - l + 1);
        tag[node] += val;
        return;
    }
    push(node, l, r);
    if (qr <= mid)
        update(lc, l, mid, ql, qr, val);
    else if (mid + 1 <= ql)
        update(rc, mid + 1, r, ql, qr, val);
    else
        update(lc, l, mid, ql, qr, val), update(rc, mid + 1, r, ql, qr, val);
    seg[node] = seg[lc] + seg[rc];
}

int query(int node, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr) 
        return seg[node];
    push(node, l, r);
    if (qr <= mid)
        return query(lc, l, mid, ql, qr);
    else if (mid + 1 <= ql)
        return query(rc, mid + 1, r, ql, qr);
    else
        return query(lc, l, mid, ql, qr) + query(rc, mid + 1, r, ql, qr);
}

signed main()
{
    int n, q;
    cin >> n >> q;

    int p, l, r, a, d;
    while (q--) {
        cin >> p;
        if (p == 1) {
            cin >> l >> r >> a >> d;
            update(1, 1, n, l, l, a);
            if (r + 1 <= n)
                update(1, 1, n, r + 1, r + 1, -(a + (r - l) * d));
            if (l + 1 <= r)
                update(1, 1, n, l + 1, r, d);
        } else {
            cin >> a;
            cout << query(1, 1, n, 1, a) << "\n";
        }
    }
    
    return 0;
}