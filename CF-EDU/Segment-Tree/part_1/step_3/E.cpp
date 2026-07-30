#include <bits/stdc++.h>
#define int long long
#define mid ((l + r) >> 1)
#define lc (node << 1)
#define rc ((node << 1) | 1)

using namespace std;

int seg[4 * 100005];
int arr[100005];

void update(int node, int l, int r, int idx, int val)
{
    if (l == r) {
        seg[node] += val;
        return;
    }
    if (idx <= mid)
        update(lc, l, mid, idx, val);
    else
        update(rc, mid + 1, r, idx, val);
    seg[node] = seg[lc] + seg[rc];
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
        return query(lc, l, mid, ql, qr) + query(rc, mid+1, r, ql, qr);
}

signed main()
{
    int n, q;
    cin >> n >> q;

    int v, l, r, k, idx;
    while (q--) {
        cin >> v;
        if (v == 1) {
            cin >> l >> r >> k;
            l++;
            update(1, 1, n + 1, l, k);
            update(1, 1, n + 1, r + 1, -k);
        } else {
            cin >> idx;
            idx++;
            cout << query(1, 1, n + 1, 1, idx) << "\n";
        }
    }
    
    return 0;
}