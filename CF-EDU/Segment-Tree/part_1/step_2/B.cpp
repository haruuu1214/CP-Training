/// find the kth {1} in the {1, 0, 1, 0, 1, 1}
#include <bits/stdc++.h>
#define int long long
#define mid ((l + r) >> 1)
#define lc (node << 1)
#define rc ((node << 1) | 1)
using namespace std;

int seg[4 * 100005];
int arr[100005];

void build(int node, int l, int r)
{
    if (l == r) {
        seg[node] = arr[l];
        return;
    }
    build(lc, l, mid);
    build(rc, mid + 1, r);
    seg[node] = seg[lc] + seg[rc];
}

void update(int node, int l, int r, int idx)
{
    if (l == r) {
        seg[node] = (seg[node] ^ 1);
        return;
    }
    if (idx <= mid)
        update(lc, l, mid, idx);
    else
        update(rc, mid + 1, r, idx);
    seg[node] = seg[lc] + seg[rc];
}

int query(int node, int l, int r, int kth)
{
    if (l == r)
        return l;
    if (kth <= seg[lc])
        return query(lc, l, mid, kth);
    else
        return query(rc, mid + 1, r, kth - seg[lc]);
}

signed main()
{
    int n, q, x, k;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    build(1, 1, n);

    int v, x, k;
    while (q--) {
        cin >> v;
        if (v == 1) {
            cin >> x;
            update(1, 1, n, x + 1);
        } else {
            cin >> k;
            cout << query(1, 1, n, k + 1) - 1 << "\n";
        }
    }
    return 0;
}