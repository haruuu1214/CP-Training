#include <bits/stdc++.h>
#define int long long
#define mid ((l + r) >> 1)
#define lc (node << 1)
#define rc ((node << 1) | 1)
using namespace std;

int seg[4 * 100005];
bool lazy[4 * 100005];

void push(int node, int l, int r)
{
    if (lazy[node] == true) {
        lazy[lc] = !lazy[lc];
        lazy[rc] = !lazy[rc];
        seg[lc] = (mid - l + 1) - seg[lc];
        seg[rc] = (r - (mid + 1) + 1) - seg[rc];
        lazy[node] = 0;
    }
}

void update(int node, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr) {
        seg[node] = (r - l + 1) - seg[node];
        lazy[node] = true;
        return;
    }
    push(node, l, r);
    if (qr <= mid)
        update(lc, l, mid, ql, qr);
    else if (mid + 1 <= ql)
        update(rc, mid + 1, r, ql, qr);
    else {
        update(lc, l, mid, ql, qr);
        update(rc, mid + 1, r, ql, qr);
    }
    seg[node] = seg[lc] + seg[rc];
}

int query(int node, int l, int r, int k)
{
    if (l == r)
        return l;
    push(node, l, r);
    if (k <= seg[lc])
        return query(lc, l, mid, k);
    else
        return query(rc, mid + 1, r, k - seg[lc]);
}

signed main()
{
    int n, q;
    cin >> n >> q;
    int v, l, r, k;
    while (q--) {
        cin >> v;
        if (v == 1) {
            cin >> l >> r;
            update(1, 1, n, l + 1, r);
        } else {
            cin >> k;
            cout << query(1, 1, n, k + 1) - 1 << "\n";
        }
    }
    
    return 0;
}