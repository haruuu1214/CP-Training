#include <bits/stdc++.h>
#define int long long
#define lc (node << 1)
#define rc ((node << 1) | 1)
#define mid ((l + r) >> 1)
using namespace std;

const int N = 100005;
int seg[4 * N];
int tag[4 * N];

void push(int node, int l, int r)
{
    if (tag[node] != 0) {
        seg[lc] += tag[node];
        seg[rc] += tag[node];
        tag[lc] += tag[node];
        tag[rc] += tag[node];
        tag[node] = 0;
    }
}

void update(int node, int l, int r, int ql, int qr, int val)
{
    if (ql <= l && r <= qr) {
        seg[node] += val;
        tag[node] += val;
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
    seg[node] = max(seg[lc], seg[rc]);
}

int query(int node, int l, int r, int idx, int x)
{
    if (seg[node] < x)
        return 0;
    if (l == r)
        return l;
    push(node, l, r);
    if (mid < idx) {
        return query(rc, mid + 1, r, idx, x);
    } else {
        int v = query(lc, l, mid, idx, x);
        if (v == 0)
            return query(rc, mid + 1, r, idx, x);
        else
            return v;
    }
}

signed main()
{
    int n, q;
    cin >> n >> q;

    int p, l, r, v, idx, x;
    while (q--) {
        cin >> p;
        if (p == 1) {
            cin >> l >> r >> v;
            update(1, 1, n, l + 1, r, v);
        } else {
            cin >> x >> idx;
            cout << query(1, 1, n, idx + 1, x) - 1 << "\n";
        }
    }
    
    return 0;
}