#include <bits/stdc++.h>
#define int long long
#define mid ((l + r) >> 1)
#define lc (node << 1)
#define rc ((node << 1) | 1)
using namespace std;

int seg[4 * 100005], ass[4 * 100005];

void push(int node, int l, int r)
{
    if (ass[node] != -1) {
        seg[lc] = ass[node];
        seg[rc] = ass[node];
        ass[lc] = ass[node];
        ass[rc] = ass[node];
        ass[node] = -1;
        return;
    }
}

void update(int node, int l, int r, int ql, int qr, int val)
{
    if (ql <= l && r <= qr) {
        seg[node] = val;
        ass[node] = val;
        return;
    }
    push(node, l, r);
    if (qr <= mid)
        update(lc, l, mid, ql, qr, val);
    else if (mid + 1 <= ql)
        update(rc, mid + 1, r, ql, qr, val);
    else {
        update(lc, l, mid, ql, qr, val);
        update(rc, mid + 1, r, ql, qr, val);
    }
    seg[node] = min(seg[lc], seg[rc]);
}

int query(int node, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr) {
        return seg[node];
    }
    push(node, l, r);
    if (qr <= mid)
        return query(lc, l, mid, ql, qr);
    else if (mid + 1 <= ql)
        return query(rc, mid + 1, r, ql, qr);
    else
        return min(query(lc, l, mid, ql, qr), query(rc, mid + 1, r, ql, qr));
}

signed main()
{
    fill(ass, ass + 4 * 100005, -1);
    int n, q;
    cin >> n >> q;

    int v, l, r, idx, val;
    while (q--) {
        cin >> v;
        if (v == 1) {
            cin >> l >> r >> val;
            update(1, 1, n, l + 1, r, val);
        } else {
            cin >> l >> r;
            cout << query(1, 1, n, l + 1, r) << "\n";
        }
    }
    return 0;
}