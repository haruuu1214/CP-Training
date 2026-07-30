/// ...y...x..x..y
/// y 線段中包含 x 線段
#include <bits/stdc++.h>
#define int long long
#define mid ((l + r) >> 1)
#define lc (node << 1)
#define rc ((node << 1) | 1)

using namespace std;

int seg[4 * 200005];
int left_idx[200005];
int ans[200005];

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
    else {
        return query(lc, l, mid, ql, qr) + query(rc, mid + 1, r, ql, qr);
    }
}

signed main()
{
    int n, x;
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> x;
        if (left_idx[x] != 0) {
            ans[x] = query(1, 1, 2 * n, left_idx[x], i);
            update(1, 1, 2 * n, left_idx[x], 1);
        } else {
            left_idx[x] = i;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";

    return 0;
}