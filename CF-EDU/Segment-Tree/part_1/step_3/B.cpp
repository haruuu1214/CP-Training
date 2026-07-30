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
        seg[node] = 1;
        return;
    }
    build(lc, l, mid);
    build(rc, mid + 1, r);
    seg[node] = seg[lc] + seg[rc];
}

void update(int node, int l, int r, int idx)
{
    if (l == r) {
        seg[node] = 0;
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

int ans[100005];

signed main()
{
    int n, q, x, k;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    build(1, 1, n);
    
    int now = n;
    for (int i = n; i >= 1; i--) {
        ans[i] = query(1, 1, n, now - arr[i]);
        update(1, 1, n, ans[i]);
        now--;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
    
    return 0;
}