#include <bits/stdc++.h>
#define int long long
#define mid ((l + r) >> 1)
#define lc (node << 1)
#define rc ((node << 1) | 1)
using namespace std;

const int INF = 1e15;
int seg[4 * 100005];
int ans;

void update(int node, int l, int r, int idx, int val)
{
    if (l == r) {
        seg[node] = val;
        return;
    }
    if (idx <= mid)
        update(lc, l, mid, idx, val);
    else
        update(rc, mid + 1, r, idx, val);
    seg[node] = min(seg[lc], seg[rc]);
}

void query(int node, int l, int r, int ql, int qr, int val)
{
    if (l == r) {
        if (seg[node] <= val) {
            seg[node] = INF;
            ans++;
        }
        return;
    }
    if (qr <= mid) {
        if (seg[lc] <= val)
            query(lc, l, mid, ql, qr, val);
    } else if (mid + 1 <= ql) {
        if (seg[rc] <= val)
            query(rc, mid + 1, r, ql, qr, val);
    } else {
        if (seg[lc] <= val)
            query(lc, l, mid, ql, qr, val);
        if (seg[rc] <= val)
            query(rc, mid + 1, r, ql, qr, val);
    }
    seg[node] = min(seg[lc], seg[rc]);
}

signed main()
{
    fill(seg, seg + 4 * 100005, INF);
    int n, q;
    cin >> n >> q;

    int v, x, k, l, r, p;
    while (q--) {
        cin >> v;
        if (v == 1) {
            cin >> x >> k;
            update(1, 1, n, x + 1, k);
        } else {
            cin >> l >> r >> p;
            ans = 0;
            query(1, 1, n, l + 1, r, p);
            cout << ans << "\n";
        }
    }
    
    return 0;
}