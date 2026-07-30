/// find the first element bigger than X and the index needs to > IDX
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
    seg[node] = max(seg[lc], seg[rc]);
}

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
    seg[node] = max(seg[lc], seg[rc]);
}

int query(int node, int l, int r, int X, int idx)
{
    if (seg[node] < X)
        return 0;
    if (l == r)
        return l;
    if (mid + 1 <= idx)
        return query(rc, mid + 1, r, X, idx);
    else {
        int tmp = query(lc, l, mid, X, idx);
        if (tmp != 0)
            return tmp;
        else
            return query(rc, mid + 1, r, X, idx);
    }
}

signed main()
{
    int n, q, x, k;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    build(1, 1, n);

    int v, x, k, idx;
    while (q--) {
        cin >> v;
        if (v == 1) {
            cin >> x >> k;
            update(1, 1, n, x + 1, k);
        } else {
            cin >> k >> idx;
            cout << query(1, 1, n, k, idx + 1) - 1 << "\n";
        }
    }
    
    return 0;
}

