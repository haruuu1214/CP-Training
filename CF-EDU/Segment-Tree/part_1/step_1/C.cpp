#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define mid ((l + r) >> 1)
#define lc (node << 1)
#define rc ((node << 1) | 1)
using namespace std;

pii seg[4 * 100005];
int arr[100005];

void combine(int node)
{
    seg[node].first = min(seg[lc].first, seg[rc].first);
    if (seg[lc].first == seg[rc].first)
        seg[node].second = seg[lc].second + seg[rc].second;
    else
        seg[node].second = (seg[lc].first < seg[rc].first ? seg[lc].second : seg[rc].second);
}

void build(int node, int l, int r)
{
    if (l == r) {
        seg[node] = {arr[l], 1};
        return;
    }
    build(lc, l, mid);
    build(rc, mid + 1, r);
    combine(node);
}

void update(int node, int l, int r, int idx, int val)
{
    if (l == r) {
        seg[node] = {val, 1};
        return;
    }
    if (idx <= mid)
        update(lc, l, mid, idx, val);
    else
        update(rc, mid + 1, r, idx, val);
    combine(node);
}

pii query(int node, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
        return seg[node];
    if (qr <= mid)
        return query(lc, l, mid, ql, qr);
    else if (mid + 1 <= ql)
        return query(rc, mid + 1, r, ql, qr);
    else {
        pii a = query(lc, l, mid, ql, qr);
        pii b = query(rc, mid + 1, r, ql, qr);
        if (a.first == b.first)
            return {a.first, a.second + b.second};
        else {
            int cnt;
            if (a.first < b.first)
                cnt = a.second;
            else
                cnt = b.second;
            return {min(a.first, b.first), cnt};
        }
    }
}

signed main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    build(1, 1, n);

    int v, x, k, l, r;
    while (q--) {
        cin >> v;
        if (v == 1) {
            cin >> x >> k;
            update(1, 1, n, x + 1, k);
        } else {
            cin >> l >> r;
            pii Q = query(1, 1, n, l + 1, r);
            cout << Q.first << " " << Q.second << "\n";
        }
    }
    
    return 0;
}