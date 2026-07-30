#include <bits/stdc++.h>
#define int long long
#define mid ((l + r) >> 1)
#define lc (node << 1)
#define rc ((node << 1) | 1)
using namespace std;

const int mod = 1e9 + 7;

int seg[4 * 100005], mul[4 * 100005];

void build(int node, int l, int r)
{
    if (l == r) {
        seg[node] = 1;
        return;
    }
    build(lc, l, mid);
    build(rc, mid + 1, r);
    seg[node] = seg[lc] + seg[rc];
}

void push(int node, int l, int r)
{
    if (mul[node] != 1) {
        seg[lc] = (seg[lc] * mul[node]) % mod;
        seg[rc] = (seg[rc] * mul[node]) % mod;
        mul[lc] = (mul[lc] * mul[node]) % mod;
        mul[rc] = (mul[rc] * mul[node]) % mod;
        mul[node] = 1;
    }
}

void update(int node, int l, int r, int ql, int qr, int val)
{
    if (ql <= l && r <= qr) {
        seg[node] = (seg[node] * val) % mod;
        mul[node] = (mul[node] * val) % mod;
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
    seg[node] = (seg[lc] + seg[rc]) % mod;
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
        return (query(lc, l, mid, ql, qr) + query(rc, mid + 1, r, ql, qr)) % mod;
}

signed main()
{
    int n, q;
    cin >> n >> q;

    fill(mul, mul + 4 * 100005, 1);

    build(1, 1, n);

    int v, l, r, val;
    while (q--) {
        cin >> v;
        if (v == 1) {
            cin >> l >> r >> val;
            update(1, 1, n, l + 1, r, val % mod);
        } else {
            cin >> l >> r;
            cout << query(1, 1, n, l + 1, r) << "\n";
        }
    }
    return 0;
}