#pragma GCC optimize("Ofast, unroll-loops, O3")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int INF = INT32_MAX;
const int N = 100005;
int n, a[N];

struct Node1 {
    Node1 *lc = nullptr, *rc = nullptr;
    int val;
    Node1(int _val = 0) : val(_val) {}
};

Node1 *build1(int l, int r) {
    Node1 *node = new Node1();
    if (l == r) {
        node->val = INF;
        return node;
    }
    int mid = (l + r) >> 1;
    node->lc = build1(l, mid);
    node->rc = build1(mid + 1, r);
    node->val = min(node->lc->val, node->rc->val);
    return node;
}

void update1(Node1 *node, int l, int r, int id, int val) {
    if (l == r) {
        node->val = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (id <= mid)
        update1(node->lc, l, mid, id, val);
    else
        update1(node->rc, mid + 1, r, id, val);
    node->val = min(node->lc->val, node->rc->val);
}

struct Node2 {
    Node2 *lc = nullptr, *rc = nullptr;
    int val;
    Node2(int _val = 0) : val(_val) {}
};

Node2 *build2(int l, int r) {
    Node2 *node = new Node2();
    if (l == r) {
        node->val = -INF;
        return node;
    }
    int mid = (l + r) >> 1;
    node->lc = build2(l, mid);
    node->rc = build2(mid + 1, r);
    node->val = max(node->lc->val, node->rc->val);
    return node;
}

void update2(Node2 *node, int l, int r, int id, int val) {
    if (l == r) {
        node->val = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (id <= mid)
        update2(node->lc, l, mid, id, val);
    else
        update2(node->rc, mid + 1, r, id, val);
    node->val = max(node->lc->val, node->rc->val);
}

int bin_find_small(Node1 *node, int l, int r, int lo, int x) {
    if (l == r) {
        if (l < lo)
            return n + 1;
        if (node->val <= x)
            return l;
        return n + 1;
    }
    int mid = (l + r) >> 1;
    if (lo > mid)
        return bin_find_small(node->rc, mid + 1, r, lo, x);
    else {
        if (node->lc->val <= x) {
            int id = bin_find_small(node->lc, l, mid, lo, x);
            if (id >= lo && id <= n)
                return id;
        }
        return bin_find_small(node->rc, mid + 1, r, lo, x);
    }
}

int bin_find_big(Node2 *node, int l, int r, int lo, int x) {
    if (l == r) {
        if (l < lo)
            return n + 1;
        if (node->val >= x)
            return l;
        return n + 1;
    }
    int mid = (l + r) >> 1;
    if (lo > mid)
        return bin_find_big(node->rc, mid + 1, r, lo, x);
    else {
        if (node->lc->val >= x) {
            int id = bin_find_big(node->lc, l, mid, lo, x);
            if (id >= lo && id <= n)
                return id;
        }
        return bin_find_big(node->rc, mid + 1, r, lo, x);
    }
}

int ans_seg[4 * N];
void update(int node, int l, int r, int id, int val) {
    if (l == r) {
        ans_seg[node] = min(ans_seg[node], val);
        return;
    }
    int mid = (l + r) >> 1;
    if (id <= mid)
        update((node << 1), l, mid, id, val);
    else
        update(((node << 1) | 1), mid + 1, r, id, val);
    ans_seg[node] = min(ans_seg[(node << 1)], ans_seg[((node << 1) | 1)]);
}

int query(int node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
        return ans_seg[node];
    int mid = (l + r) >> 1;
    if (qr <= mid)
        return query((node << 1), l, mid, ql, qr);
    else if (mid + 1 <= ql)
        return query(((node << 1) | 1), mid + 1, r, ql, qr);
    else
        return min(query((node << 1), l, mid, ql, qr), query(((node << 1) | 1), mid + 1, r, ql, qr));
}

struct queries {
    int qid, l, r;
};
int ans[N];
Node1 *rt1; // 找 位置 >= i 且 第一個比 x 小的數字 但又不能比現在數字小
Node2 *rt2; // 找 位置 >= i 且 第一個比 x 大的數字 但又不能比現在數字大
vector<pii> upd[N];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    fill(ans_seg, ans_seg + 4 * N, INF);
    cin >> n;
    vector<pii> ord1, ord2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ord1.push_back({a[i], i});
        ord2.push_back({a[i], i});
    }
    int q;
    cin >> q;
    vector<queries> qry(q);
    for (int i = 0; i < q; i++) {
        cin >> qry[i].l >> qry[i].r;
        qry[i].qid = i;
    }

    rt1 = build1(1, n);
    rt2 = build2(1, n);
    sort(ord1.begin(), ord1.end(), [&](pii p, pii q) {
        if (p.first != q.first)
            return p.first > q.first;
        return p.second > q.second;
    });
    sort(ord2.begin(), ord2.end(), [&](pii p, pii q) {
        if (p.first != q.first)
            return p.first < q.first;
        return p.second > q.second;
    });
    for (int i = 0; i < n; i++) {
        auto [val1, idx1] = ord1[i];
        int now = val1;
        int tar, pos, tmp;
        // update bigger
        pos = bin_find_small(rt1, 1, n, idx1 + 1, INF - 1);
        while (pos <= n) {
            if (0 <= a[pos] - now && a[pos] - now <= INF)
                upd[idx1].emplace_back(pos, a[pos] - now);
            tar = (now + a[pos]) / 2;
            if (pos + 1 > n) break;
            tmp = bin_find_small(rt1, 1, n, pos + 1, tar);
            pos = tmp;
        }

        auto [val2, idx2] = ord2[i];
        now = val2;
        // update smaller
        pos = bin_find_big(rt2, 1, n, idx2 + 1, -INF + 1);
        while (pos <= n) {
            if (0 <= now - a[pos] && now - a[pos] <= INF)
                upd[idx2].emplace_back(pos, now - a[pos]);
            tar = (now + a[pos]) / 2;
            if (pos + 1 > n) break;
            tmp = bin_find_big(rt2, 1, n, pos + 1, tar);
            pos = tmp;
        }
        update1(rt1, 1, n, idx1, val1);
        update2(rt2, 1, n, idx2, val2);
    }
    sort(qry.begin(), qry.end(), [&](queries p, queries q) {
        return p.l > q.l;
    });

    int id = 0;
    for (int l = n; l >= 1; l--) {
        for (auto [id, va] : upd[l])
            update(1, 1, n, id, va);
        while (id < q && qry[id].l == l) {
            ans[qry[id].qid] = query(1, 1, n, qry[id].l, qry[id].r);
            id += 1;
        }
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
    
    return 0;
}