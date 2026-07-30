#include <bits/stdc++.h>
#define int long long
using namespace std;
#define mid ((l + r) >> 1)
#define lc (node << 1)
#define rc ((node << 1) | 1)
struct Polynomial
{
    int N;
    vector <int> info, tag, d;
    Polynomial(int n) : N(n), info(4 * n + 5), tag(4 * n + 5), d(4 * n + 5) {}
    Polynomial(vector <int> init) : Polynomial(init.size()) {
        function <void(int, int, int)> build = [&](int node, int l, int r) {
            if (l == r) {
                info[node] = init[l - 1];
                return;
            }
            build(lc, l, mid);
            build(rc, mid + 1, r);
            pull(node);
        };
        build(1, 1, N);
    }
    int merge(int a, int b) {
        return a + b; /// 自定義
    }
    void push(int node, int l, int r) {
        info[lc] += (mid - l + 1) * (2 * tag[node] + (mid - l) * d[node]) / 2ll;
        info[rc] += (r - mid) * (2 * tag[node] + (mid + 1 - l) * d[node] + (r - l) * d[node]) / 2ll;
        tag[lc] += tag[node];
        tag[rc] += tag[node] + (mid + 1 - l) * d[node];
        d[lc] += d[node];
        d[rc] += d[node];
        tag[node] = d[node] = 0;
    }
    void pull(int node) {
        info[node] = merge(info[(node << 1)], info[((node << 1) | 1)]);
    }
    void update(int node, int l, int r, int ql, int qr, int _start, int _d) {
        if (ql <= l && r <= qr) {
            info[node] += (r - l + 1) * (2 * _start + (r - l) * _d) / 2ll;
            tag[node] += _start;
            d[node] += _d;
            return;
        }
        push(node, l, r);
        if (qr <= mid)
            update(lc, l, mid, ql, qr, _start, _d);
        else if (mid + 1 <= ql)
            update(rc, mid + 1, r, ql, qr, _start + max(0ll, mid + 1 - max(l, ql)) * _d, _d);
        else {
            update(lc, l, mid, ql, qr, _start, _d);
            update(rc, mid + 1, r, ql, qr, _start + max(0ll, mid + 1 - max(l, ql)) * _d, _d);
        }
        pull(node);
    }
    int query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return info[node];
        push(node, l, r);
        if (qr <= mid)
            return query(lc, l, mid, ql, qr);
        else if (mid + 1 <= ql)
            return query(((node << 1) | 1), mid + 1, r, ql, qr);
        else
            return merge(query((node << 1), l, mid, ql, qr), query(((node << 1) | 1), mid + 1, r, ql, qr));
    }
    void update(int l, int r, int _start, int _d) { update(1, 1, N, l, r, _start, _d); }
    int query(int l, int r) { return query(1, 1, N, l, r); }
};
struct Normal
{
    vector <int> data;
    vector <int> add;
    int N;
    Normal(int n) : N(n), data(4 * n + 5), add(4 * n + 5) {}
    Normal(vector <int> init) : Normal(init.size()) { /// init : [0, N-1]
        function <void(int, int, int)> build = [&](int node, int l, int r) {
            if (l == r) {
                data[node] = init[l - 1];
                return;
            }
            build(lc, l, mid);
            build(rc, mid + 1, r);
            pull(node);
        };
        build(1, 1, N);
    }
    void pull(int node) { data[node] = data[lc] + data[rc]; }
    void push(int node, int l, int r) {
        if (l == r) return;
        if (add[node] != 0) {
            data[lc] += (mid - l + 1) * add[node];
            data[rc] += (r - (mid + 1) + 1) * add[node];
            add[lc] += add[node];
            add[rc] += add[node];
            add[node] = 0;
        }
    }
    void update(int node, int l, int r, int ql, int qr, int val) {
        if (ql <= l && r <= qr) {
            data[node] += (r - l + 1) * val;
            add[node] += val;
            return;
        }
        push(node, l, r);
        if (qr <= mid)
            update(lc, l, mid, ql, qr, val);
        else if (mid + 1 <= ql)
            update(rc, mid+1, r, ql, qr, val);
        else {
            update(lc, l, mid, ql, qr, val);
            update(rc, mid+1, r, ql, qr, val);
        }
        pull(node);
    }
    int query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return data[node];
        push(node, l, r);
        if (qr <= mid)
            return query(lc, l, mid, ql, qr);
        else if (mid+1 <= ql)
            return query(rc, mid+1, r, ql, qr);
        else
            return query(lc, l, mid, ql, qr) + query(rc, mid+1, r, ql, qr);
    }
    void update(int l, int r, int val) { update(1, 1, N, l, r, val); }
    int query(int l, int r) { return query(1, 1, N, l, r); }
};
signed main()
{
    int n, q;
    cin >> n >> q;
    vector <int> v1, v2;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        v1.push_back(x * i);
        v2.push_back(x);
    }
    Polynomial P(v1);
    Normal S(v2);
    int op, l, r, d;
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> l >> r >> d;
            P.update(l, r, l * d, d);
            S.update(l, r, d);
        } else {
            cin >> l >> r;
            cout << P.query(l, r) - (l - 1) * S.query(l, r) << "\n";
        }
    }
    return 0;
}