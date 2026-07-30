#include <bits/stdc++.h>
#define int long long
#define mid ((l + r) >> 1)
#define lc (node << 1)
#define rc ((node << 1) | 1)
using namespace std;

int add[4 * 100005];

void update(int node, int l, int r, int ql, int qr, int val)
{
    if (ql <= l && r <= qr) {
        add[node] += val;
        return;
    }
    if (qr <= mid)
        update(lc, l, mid, ql, qr, val);
    else if (mid + 1 <= ql)
        update(rc, mid + 1, r, ql, qr, val);
    else {
        update(lc, l, mid, ql, qr, val);
        update(rc, mid + 1, r, ql, qr, val);
    }
}

int query(int node, int l, int r, int idx)
{
    if (l == r)
        return add[node];
    int x;
    if (idx <= mid)
        x = query(lc, l, mid, idx);
    else
        x = query(rc, mid + 1, r, idx);
    return x+add[node];
}

signed main()
{
    int n, q;
    cin >> n >> q;

    int v, l, r, idx, val;
    while (q--) {
        cin >> v;
        if (v == 1) {
            cin >> l >> r >> val;
            update(1, 1, n, l + 1, r, val);
        } else {
            cin >> idx;
            cout << query(1, 1, n, idx + 1) << "\n";
        }
    }
}