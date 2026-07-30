#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define siz(x) (int)x.size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// ---------------------------------------------

const int N = 600005;

struct Node {
    int mx, premx, sufmx, sum;
    Node(int _x = 0) : mx(max(0ll, _x)), premx(max(0ll, _x)), sufmx(max(0ll, _x)), sum(_x) {}
};
Node combine(Node a, Node b) {
    Node c;
    c.premx = max(a.premx, a.sum + b.premx);
    c.sufmx = max(b.sufmx, b.sum + a.sufmx);
    c.sum = a.sum + b.sum;
    c.mx = max({a.mx, b.mx, a.sufmx + b.premx});
    return c;
}
Node rev(Node a) {
    Node c;
    c.mx = a.mx; c.sum = a.sum;
    c.premx = a.sufmx; c.sufmx = a.premx;
    return c;
}
Node a[N];
Node tmp[N];

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
        build((node << 1), l, mid);
        build(((node << 1) | 1), mid + 1, r);
        seg[node] = combine(seg[node << 1], seg[(node << 1) | 1]);
    }
    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return seg[node];
        int mid = (l + r) >> 1;
        if (qr <= mid)
            return query((node << 1), l, mid, ql, qr);
        else if (mid + 1 <= ql)
            return query(((node << 1) | 1), mid + 1, r, ql, qr);
        else
            return combine(query((node << 1), l, mid, ql, qr), query(((node << 1) | 1), mid + 1, r, ql, qr));
    }
};
vector <int> G[N];

struct HLD {
    Segment_Tree seg;
    vector<int> pa, sz, depth, mxson, topf, id;
    int n, idcnt = 0;
    HLD(int _n) : n(_n), pa(_n + 1), sz(_n + 1), depth(_n + 1), mxson(_n + 1), topf(_n + 1), id(_n + 1), seg(_n) {}
    void dfs1(int v = 1, int p = -1) {
        pa[v] = p; sz[v] = 1; mxson[v] = 0; 
        depth[v] = (p == -1 ? 0 : depth[p] + 1);
        for (int u : G[v]) {
            if (u == p) continue;
            dfs1(u, v);
            sz[v] += sz[u];
            if (sz[u] > sz[mxson[v]]) mxson[v] = u;
        }
    }
    void dfs2(int v = 1, int top = 1) {
        id[v] = ++idcnt;
        topf[v] = top;
        if (mxson[v]) dfs2(mxson[v], top);
        for (int u : G[v]) {
            if (u == mxson[v] || u == pa[v]) continue;
            dfs2(u, u);
        }
    }
    /// query 為區間資料結構
    int path_query(int a, int b) {
        Node head, tail;
        while (topf[a] != topf[b]) { /// 若不在同一條鍊上
            if (depth[topf[a]] < depth[topf[b]]) {
                // cout << "tail : "; cout << topf[b] << " " << b << "\n";
                tail = combine(seg.query(1, 1, n, id[topf[b]], id[b]), tail);
                b = pa[topf[b]];
            } else {
                // cout << "head : "; cout << a << " " << topf[a] << "\n";
                head = combine(head, rev(seg.query(1, 1, n, id[topf[a]], id[a])));
                a = pa[topf[a]];
            }
        }
        /// 此時已在同一條鍊上
        if (depth[a] < depth[b]) {
            // cout << "tail : "; cout << a << " " << b << "\n";
            tail = combine(seg.query(1, 1, n, id[a], id[b]), tail);
        } else {
            // cout << "head : "; cout << a << " " << b << "\n";
            head = combine(head, rev(seg.query(1, 1, n, id[b], id[a])));
        }
        return combine(head, tail).mx;
    }
};

signed main() {
    IO;
    int n, q, v, u, w;
    cin >> n >> q;
    int nodecnt = n;
    FOR (i, 1, n - 1) {
        cin >> v >> u >> w;
        nodecnt++;
        G[v].push_back(nodecnt);
        G[nodecnt].push_back(v);
        G[u].push_back(nodecnt);
        G[nodecnt].push_back(u);
        tmp[nodecnt] = Node(w);
    }
    HLD hld(nodecnt);
    hld.dfs1();
    hld.dfs2();
    FOR (i, 1, nodecnt)
        if (tmp[i].sum != 0)
            a[hld.id[i]] = tmp[i];
    hld.seg.build(1, 1, nodecnt);
    while (q--) {
        cin >> v >> u;
        cout << hld.path_query(v, u) << "\n";
    }
}