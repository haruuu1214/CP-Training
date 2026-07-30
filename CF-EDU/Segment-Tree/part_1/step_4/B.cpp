#include <bits/stdc++.h>
#define int long long
#define mid ((l+r) >> 1)
#define lc (node << 1)
#define rc ((node << 1) | 1)
#define matrix array<array<int, 2>, 2>
using namespace std;

int mod;
matrix operator*(matrix A, matrix B)
{
    matrix C;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= mod;
            }
        }
    }
    return C;
}

matrix seg[4 * 200005];
matrix a[200005];

void build(int node, int l, int r)
{
    if (l == r) {
        seg[node] = a[l];
        return;
    }
    build(lc, l, mid);
    build(rc, mid + 1, r);
    seg[node] = seg[lc] * seg[rc];
}

matrix query(int node, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
        return seg[node];
    
    if (qr <= mid)
        return query(lc, l, mid, ql, qr);
    else if (mid + 1 <= ql)
        return query(rc, mid + 1, r, ql, qr);
    else
        return query(lc, l, mid, ql, qr) * query(rc, mid + 1, r, ql, qr);
}

signed main()
{
    int n, q;
    cin >> mod >> n >> q;
    for (int i = 1; i <= n; i++) {
        for (int x = 0; x <= 1; x++) {
            for (int y = 0; y <= 1; y++) {
                cin >> a[i][x][y];
            }
        }
    }
    build(1, 1, n);

    int l, r;
    while (q--) {
        cin >> l >> r;
        matrix ans = query(1, 1, n, l, r);

        for (int x = 0; x <= 1; x++) {
            for (int y = 0; y <= 1; y++) {
                cout << ans[x][y] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}
