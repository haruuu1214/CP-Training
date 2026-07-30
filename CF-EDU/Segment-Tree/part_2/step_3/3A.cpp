#include <bits/stdc++.h>
#define int long long
#define mid ((l + r) >> 1)
#define lc (node << 1)
#define rc ((node << 1) | 1)
using namespace std;

int seg[4 * 100005], pre[4 * 100005], suf[4 * 100005], sum[4 * 100005], lazy[4 * 100005];
const int INF = 1e15;

void combine(int node)
{
    sum[node] = sum[lc] + sum[rc];
    pre[node] = max(pre[lc], sum[rc] + pre[rc]);
    suf[node] = max(suf[lc], sum[rc] + suf[lc]);
    seg[node] = max({seg[lc], seg[rc], suf[lc] + pre[rc]});
}

void push(int node, int l, int r)
{
    if (lazy[node] != INF) {
        lazy[lc] = lazy[node];
        lazy[rc] = lazy[node];
        sum[lc] = lazy[node] * (mid - l + 1);
        seg[lc] = pre[lc] = suf[lc] = (lazy[node] > 0 ? lazy[node] * (mid - l + 1) : 0);
        sum[rc] = lazy[node] * (r - (mid + 1) + 1);
        seg[rc] = pre[rc] = suf[rc] = (lazy[node] > 0 ? lazy[node] * (r - (mid + 1) + 1) : 0);
        lazy[node] = INF;
    }
}

void update(int node, int l, int r, int ql, int qr, int v)
{
    if (ql <= l && r <= qr) {
        lazy[node] = v;
        sum[node] = v * (r - l + 1);
        seg[node] = pre[node] = suf[node] = (v > 0 ? v * (r - l + 1) : 0);
        return;
    }
    push(node, l, r);
    if (qr <= mid)
        update(lc, l, mid, ql, qr, v);
    else if (mid + 1 <= ql)
        update(rc, mid + 1, r, ql, qr, v);
    else {
        update(lc, l, mid, ql, qr, v);
        update(rc, mid + 1, r, ql, qr, v);
    }
    combine(node);
}

signed main()
{
    fill(lazy, lazy + 4 * 100005, INF);
    int n, q;
    cin >> n >> q;

    int a, b, c;
    while (q--) {
        cin >> a >> b >> c;
        update(1, 1, n, a + 1, b, c);
        cout << seg[1] << "\n";
    }
    
    return 0;
}