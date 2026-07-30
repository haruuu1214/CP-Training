#include <bits/stdc++.h>
#define int long long
#define mid ((l + r) >> 1)
#define lc (node << 1)
#define rc ((node << 1) | 1)
using namespace std;

int arr[100005];

struct point
{
    int cnt;
    int num[41];
    void combine(const point& lnode, const point& rnode) {
        cnt = 0;
        for (int i = 1; i <= 40; i++) {
            num[i] = lnode.num[i] + rnode.num[i];
            if (num[i] > 0)
                cnt++;
        }
    }
} seg[4 * 100005];

void build(int node, int l, int r)
{
    if (l == r) {
        seg[node].cnt = 1;
        seg[node].num[arr[l]]++;
        return;
    }
    build(lc, l, mid);
    build(rc, mid + 1, r);
    seg[node].combine(seg[lc], seg[rc]);
}

void update(int node, int l, int r, int idx, int val)
{
    if (l == r) {
        seg[node].num[arr[l]]--;
        seg[node].num[val]++;
        return;
    }
    if (idx <= mid)
        update(lc, l, mid, idx, val);
    else
        update(rc, mid + 1, r, idx, val);
    seg[node].combine(seg[lc], seg[rc]);
}

point query(int node, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
        return seg[node];
    if (qr <= mid)
        return query(lc, l, mid, ql, qr);
    else if (mid + 1 <= ql)
        return query(rc, mid + 1, r, ql, qr);
    else {
        point result;
        result.combine(query(lc, l, mid, ql, qr), query(rc, mid + 1, r, ql, qr));
        return result;
    }
}

signed main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    build(1, 1, n);

    int v, l, r, idx, val;
    while (q--) {
        cin >> v;
        if (v == 1) {
            cin >> l >> r;
            point ans;
            ans = query(1, 1, n, l, r);
            cout << ans.cnt << "\n";
        } else {
            cin >> idx >> val;
            update(1, 1, n, idx, val);
            arr[idx] = val;
        }
    }
    return 0;
}