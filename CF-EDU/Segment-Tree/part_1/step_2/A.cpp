/*
pre -> max(left pre, left sum + right pre)
suf -> max(right suf, right sum + left suf)
sum -> left sum + right sum
mx  -> max(left mx, right mx, left suf + right pre) 
*/
#include <bits/stdc++.h>
#define int long long
#define mid ((l + r) >> 1)
#define lc (node << 1)
#define rc ((node << 1) | 1)
using namespace std;

struct item {
    int pre, suf, sum, mx;
}seg[4 * 100005];
int arr[100005];

void pull(int node)
{
    seg[node].pre = max(seg[lc].pre, seg[lc].sum + seg[rc].pre);
    seg[node].suf = max(seg[rc].suf, seg[rc].sum + seg[lc].suf);
    seg[node].sum = seg[lc].sum + seg[rc].sum;
    seg[node].mx = max({
        seg[lc].mx,
        seg[rc].mx,
        seg[lc].suf + seg[rc].pre
    });
}

void build(int node, int l, int r)
{
    if (l == r) {
        seg[node].pre = max(0ll, arr[l]);
        seg[node].suf = max(0ll, arr[l]);
        seg[node].sum = arr[l];
        seg[node].mx = max(0ll, arr[l]);
        return;
    }
    pull(node);
}

void update(int node, int l, int r, int idx, int val)
{
    if (l == r) {
        seg[node].pre = max(0ll, arr[l]);
        seg[node].suf = max(0ll, arr[l]);
        seg[node].sum = arr[l];
        seg[node].mx = max(0ll, arr[l]);
        return;
    }
    if (idx <= mid)
        update(lc, l, mid, idx, val);
    else
        update(rc, mid + 1, r, idx, val);
    pull(node);
}

signed main()
{
    int n, q, x, k;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    build(1, 1, n);

    cout << seg[1].mx << "\n";
    while (q--) {
        cin >> x >> k;
        update(1, 1, n, x + 1, k);
        cout << seg[1].mx << "\n";
    }
    
    return 0;
}

