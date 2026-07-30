/// 由於 a[i] <= 40 非常小，因此我們建一棵線段樹，每個節點包含，逆序數列的數量 及 每個數字出現的次數
#include <bits/stdc++.h>
#define int long long
#define mid ((l + r) >> 1)
#define lc (node << 1)
#define rc ((node << 1) | 1)
using namespace std;

int pre[41];
int arr[100005];
struct point {
    int cnt;
    int num[41];
    void combine(const point& lnode, const point& rnode) {
        for (int i = 1; i <= 40; i++)
            num[i] = lnode.num[i] + rnode.num[i];
        cnt = lnode.cnt + rnode.cnt;

        pre[1] = rnode.num[1];
        for (int i = 2; i <= 40; i++)
            pre[i] = pre[i - 1] + rnode.num[i];
        int across = 0;
        for (int i = 2; i <= 40; i++)
            across += lnode.num[i] * pre[i - 1];
        cnt += across;
    }
}seg[4 * 100005];

void build(int node, int l, int r)
{
    if (l == r) {
        seg[node].num[arr[l]]++;
        seg[node].cnt = 0;
        return;
    }
    build(lc, l, mid);
    build(rc, mid + 1, r);
    seg[node].combine(seg[lc], seg[rc]);
}

void update(int node, int l, int r, int idx, int val)
{
    if (l == r) {
        seg[node].num[arr[idx]]--;
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
    else if (mid+1<=ql)
        return query(rc, mid + 1, r, ql, qr);
    else {
        point result;
        result.combine(query(lc, l, mid, ql, qr), query(rc, mid+1, r, ql, qr));
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

    int v, l, r, idx, k;
    while (q--) {
        cin >> v;
        if (v == 1) {
            cin >> l >> r;
            point ans = query(1, 1, n, l, r);
            cout << ans.cnt << "\n";
        } else {
            cin >> idx >> k;
            update(1, 1, n, idx, k);
            arr[idx] = k;
        }
    }
    
    return 0;
}