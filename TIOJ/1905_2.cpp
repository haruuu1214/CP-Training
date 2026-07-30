#pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 100005;
int n, a[N];
int min_seg[4 * N], max_seg[4 * N], ans_seg[4 * N];

void update1(int node, int l, int r, int id, int val) {
    if (l == r) {
        min_seg[node] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (id <= mid)
        update1(node << 1, l, mid, id, val);
    else
        update1(node << 1 | 1, mid + 1, r, id, val);
    min_seg[node] = min(min_seg[node << 1], min_seg[node << 1 | 1]);
}

void update2(int node, int l, int r, int id, int val) {
    if (l == r) {
        max_seg[node] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (id <= mid)
        update2(node << 1, l, mid, id, val);
    else
        update2(node << 1 | 1, mid + 1, r, id, val);
    max_seg[node] = max(max_seg[node << 1], max_seg[node << 1 | 1]);
}

int bin_find_small(int node, int l, int r, int lo, int x) {
    if (l == r) {
        if (l < lo)
            return n + 1;
        if (min_seg[node] <= x)
            return l;
        return n + 1;
    }
    int mid = (l + r) >> 1;
    if (lo > mid)
        return bin_find_small(node << 1 | 1, mid + 1, r, lo, x);
    else {
        if (min_seg[node << 1] <= x) {
            int id = bin_find_small(node << 1, l, mid, lo, x);
            if (id >= lo && id <= n)
                return id;
        }
        return bin_find_small(node << 1 | 1, mid + 1, r, lo, x);
    }
}

int bin_find_big(int node, int l, int r, int lo, int x) {
    if (l == r) {
        if (l < lo)
            return n + 1;
        if (max_seg[node] >= x)
            return l;
        return n + 1;
    }
    int mid = (l + r) >> 1;
    if (lo > mid)
        return bin_find_big(node << 1 | 1, mid + 1, r, lo, x);
    else {
        if (max_seg[node << 1] >= x) {
            int id = bin_find_big(node << 1, l, mid, lo, x);
            if (id >= lo && id <= n)
                return id;
        }
        return bin_find_big(node << 1 | 1, mid + 1, r, lo, x);
    }
}

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
vector<pii> upd[N];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    fill(min_seg, min_seg + 4 * N, INT32_MAX);
    fill(max_seg, max_seg + 4 * N, INT32_MIN);
    fill(ans_seg, ans_seg + 4 * N, INT32_MAX);
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
        pos = bin_find_small(1, 1, n, idx1 + 1, INT32_MAX - 1);
        while (pos <= n) {
            if (0 <= a[pos] - now && a[pos] - now <= INT32_MAX)
                upd[idx1].emplace_back(pos, a[pos] - now);
            tar = (now + a[pos]) / 2;
            if (pos + 1 > n) break;
            tmp = bin_find_small(1, 1, n, pos + 1, tar);
            pos = tmp;
        }

        auto [val2, idx2] = ord2[i];
        now = val2;
        // update smaller
        pos = bin_find_big(1, 1, n, idx2 + 1, INT32_MIN + 1);
        while (pos <= n) {
            if (0 <= now - a[pos] && now - a[pos] <= INT32_MAX)
                upd[idx2].emplace_back(pos, now - a[pos]);
            tar = (now + a[pos]) / 2;
            if (pos + 1 > n) break;
            tmp = bin_find_big(1, 1, n, pos + 1, tar);
            pos = tmp;
        }
        update1(1, 1, n, idx1, val1);
        update2(1, 1, n, idx2, val2);
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