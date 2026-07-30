#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define siz(x) (int)x.size()
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// ---------------------------------------------

const int N = 100005;
struct Node {
    int x, tag;
    Node(int _x = 0) : x(_x), tag(0) {}
};
Node combine(Node a, Node b) {
    return Node(a.x + b.x);
}
Node a[N];

struct Segment_Tree {
    vector<Node> seg;
    int n;
    Segment_Tree(int _n) : n(_n), seg(4 * _n + 5) {}
    void push(int node, int l, int r) {
        if (seg[node].tag) {
            int mid = (l + r) >> 1;
            seg[node << 1].x = (mid - l + 1) - seg[node << 1].x;
            seg[node << 1 | 1].x = (r - mid) - seg[node << 1 | 1].x;
            seg[node << 1].tag ^= 1;
            seg[node << 1 | 1].tag ^= 1;
            seg[node].tag = 0;
        }
    }
    void build(int node, int l, int r) {
        if (l == r) {
            seg[node] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(node << 1, l, mid);
        build(node << 1 | 1, mid + 1, r);
        seg[node] = combine(seg[node << 1], seg[node << 1 | 1]);
    }
    void update(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            seg[node].x = (r - l + 1) - seg[node].x;
            seg[node].tag ^= 1;
            return;
        }
        push(node, l, r);
        int mid = (l + r) >> 1;
        if (qr <= mid)
            update(node << 1, l, mid, ql, qr);
        else if (mid + 1 <= ql)
            update(node << 1 | 1, mid + 1, r, ql, qr);
        else {
            update(node << 1, l, mid, ql, qr);
            update(node << 1 | 1, mid + 1, r, ql, qr);
        }
        seg[node] = combine(seg[node << 1], seg[node << 1 | 1]);
    }
    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return seg[node];
        push(node, l, r);
        int mid = (l + r) >> 1;
        if (qr <= mid)
            return query(node << 1, l, mid, ql, qr);
        else if (mid + 1 <= ql)
            return query(node << 1 | 1, mid + 1, r, ql, qr);
        else
            return combine(query(node << 1, l, mid, ql, qr), query(node << 1 | 1, mid + 1, r, ql, qr));
    }
};

signed main() {
    IO;
    int n, q, o, l, r;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) a[i + 1] = Node(s[i] - '0');
    Segment_Tree seg(n);
    seg.build(1, 1, n);
    while (q--) {
        cin >> o >> l >> r;
        if (o == 1) {
            seg.update(1, 1, n, l, r);
        } else {
            int x = seg.query(1, 1, n, l, r).x;
            int y = (r - l + 1) - x;
            cout << x * y << "\n";
        }
    }
}