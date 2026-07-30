#include <bits/stdc++.h>
#define int long long
#define mid ((l + r) >> 1)
#define lc (node << 1)
#define rc ((node << 1) | 1)
using namespace std;

int seg[4 * 100005];
int ass[4 * 100005];
int add[4 * 100005];

void push(int node, int l, int r)
{
    if (ass[node] != -1) {
        seg[lc] = ass[node] * (mid - l + 1);
        seg[rc] = ass[node] * (r - (mid + 1) + 1);
        ass[lc] = ass[rc] = ass[node];
        add[lc] = add[rc] = 0;
        ass[node] = -1;
    }
    if (add[node] != 0) {
        seg[lc] += add[node] * (mid - l + 1);
        seg[rc] += add[node] * (r - (mid + 1) + 1);
        add[lc] += add[node];
        add[rc] += add[node];
        add[node] = 0;
    }
}

void assign(int node, int l, int r, int ql, int qr, int val)
{
    if (ql <= l && r <= qr) {
        seg[node] = val * (r - l + 1);
        ass[node] = val;
        add[node] = 0;
        return;
    }
    push(node, l, r);
    if (qr <= mid)
        assign(lc, l, mid, ql, qr, val);
    else if (mid + 1 <= ql)
        assign(rc, mid + 1, r, ql, qr, val);
    else
        assign(lc, l, mid, ql, qr, val), assign(rc, mid + 1, r, ql, qr, val);
    seg[node] = seg[lc] + seg[rc];
}

void update(int node, int l, int r, int ql, int qr, int val)
{
    if (ql <= l && r <= qr) {
        seg[node] += val * (r - l + 1);
        add[node] += val;
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
        return query(rc, mid+1, r, ql, qr);
    else
        return query(lc, l, mid, ql, qr) + query(rc, mid + 1, r, ql, qr);
}

signed main()
{
    fill(ass, ass + 4 * 100005, -1);
    fill(add, add + 4 * 100005, 0);

    int n, q;
    cin >> n >> q;
    int a, b, c, d;
    while (q--) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            assign(1, 1, n, b + 1, c, d);
        } else if (a == 2) {
            cin >> b >> c >> d;
            update(1, 1, n, b + 1, c, d);
        } else {
            cin >> b >> c;
            cout << query(1, 1, n, b + 1, c) << "\n";
        }
    }
    return 0;
}