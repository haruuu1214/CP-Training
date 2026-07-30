#include <bits/stdc++.h>
#define int long long
#define mid ((l + r) >> 1)
#define lc (node << 1)
#define rc ((node << 1) | 1)
using namespace std;

int seg[4 * 1000005];
int cnt[4 * 1000005];
bool isL[4 * 1000005];
bool isR[4 * 1000005];
int ass[4 * 1000005];

void combine(int node)
{
    if (isR[lc] && isL[rc])
        cnt[node] = cnt[lc] + cnt[rc] - 1;
    else
        cnt[node] = cnt[lc] + cnt[rc];
    isL[node] = isL[lc];
    isR[node] = isR[rc];
    seg[node] = seg[lc] + seg[rc];
}

void push(int node, int l, int r)
{
    if (ass[node] != -1) {
        seg[lc] = ass[node] * (mid - l + 1);
        seg[rc] = ass[node] * (r - (mid + 1) + 1);
        ass[lc] = ass[rc] = ass[node];
        if (ass[node]) {
            isL[lc] = isL[rc] = 1; isR[lc] = isR[rc] = 1; cnt[lc] = cnt[rc] = 1;
        } else {
            isL[lc] = isL[rc] = 0; isR[lc] = isR[rc] = 0; cnt[lc] = cnt[rc] = 0;
        }
        ass[node] = -1;
    }
}

void assign(int node, int l, int r, int ql, int qr, int val)
{
    if (ql <= l && r <= qr) {
        seg[node] = val * (r - l + 1);
        ass[node] = val;
        if (val) {
            cnt[node] = 1; isL[node] = 1; isR[node] = 1;
        } else {
            cnt[node] = 0; isL[node] = 0; isR[node] = 0;
        }
        return;
    }
    push(node, l, r);
    if (qr <= mid)
        assign(lc, l, mid, ql, qr, val);
    else if (mid + 1 <= ql)
        assign(rc, mid + 1, r, ql, qr, val);
    else
        assign(lc, l, mid, ql, qr, val), assign(rc, mid + 1, r, ql, qr, val);
    combine(node);
}

signed main()
{
    fill(ass, ass + 4 * 1000005, -1);

    int q;
    cin >> q;
    string s;
    int a, b;
    while (q--) {
        cin >> s >> a >> b;
        int x = 500001 + a;
        int y = x + b - 1;
        if (s[0] == 'W')
            assign(1, 1, 1000001, x, y, 0);
        else
            assign(1, 1, 1000001, x, y, 1);
        cout << cnt[1] << " " << seg[1] << "\n";
    }
    return 0;
}