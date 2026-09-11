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

const int mod = 998244353;
const int N = 500005;

struct Node {
    int x;
    Node(int _x = 0) : x(_x) {}
};
Node combine(Node a, Node b) {
    return Node(a.x + b.x);
}
Node a[N];

struct Segment_Tree {
    vector<Node> seg;
    int n;
    Segment_Tree(int _n) : n(_n), seg(4 * _n + 5) {}
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
    void update(int node, int l, int r, int id, int va) {
        if (l == r) {
            seg[node].x += va;
            return;
        }
        int mid = (l + r) >> 1;
        if (id <= mid)
            update(node << 1, l, mid, id, va);
        else
            update(node << 1 | 1, mid + 1, r, id, va);
        seg[node] = combine(seg[node << 1], seg[node << 1 | 1]);
    }
    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return seg[node];
        int mid = (l + r) >> 1;
        if (qr <= mid)
            return query(node << 1, l, mid, ql, qr);
        else if (mid + 1 <= ql)
            return query(node << 1 | 1, mid + 1, r, ql, qr);
        else
            return combine(query(node << 1, l, mid, ql, qr), query(node << 1 | 1, mid + 1, r, ql, qr));
    }
};
int b[N], c[N];
int appear[N];

signed main() {
    IO;
    
    int n, m;
    cin >> n >> m;

    FOR (i, 1, n)
        cin >> b[i];
    
    Segment_Tree s(n);
    FOR (i, 1, n) {
        if (appear[b[i]] == 0) {
            appear[b[i]] = i;
            s.update(1, 1, n, i, 1);
            if (i - 1 >= 1) {
                int tmp = s.query(1, 1, n, 1, i - 1).x;
                c[tmp] += 1;
            }
        } else {
            if (appear[b[i]] + 1 <= i - 1) {
                int tmp = s.query(1, 1, n, appear[b[i]] + 1, i - 1).x;
                // cout << appear[b[i]] + 1 << ' ' << i - 1 << " " << tmp << '\n';
                c[tmp] += 1;
            }
            s.update(1, 1, n, appear[b[i]], -1);
            appear[b[i]] = i;
            
            s.update(1, 1, n, i, 1);
        }
    }
    // int tmp = 0;
    // FOR (i, 1, n - 1) if (b[i] != b[i + 1]) tmp += 1; c[1] = tmp;
    for (int i = n; i >= 1; i--) c[i] += c[i + 1];
    FOR (i, 1, m) cout << c[i] << " ";
}