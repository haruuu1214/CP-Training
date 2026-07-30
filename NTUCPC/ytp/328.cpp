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

const int N = 200005;
const int mod = 998244353;
int a[N];
struct Sparse_table {
    int n;
    vector<vector<int>> st;
    Sparse_table(int _n) : n(_n), st(_n + 1, vector<int>(__lg(_n) + 1)) {
        for (int i = 1; i <= n; i++) st[i][0] = a[i];
        for (int lg = 1; lg <= __lg(n); lg++) {
            int len = 1 << (lg - 1);
            for (int i = 1; i + len <= n; i++)
                st[i][lg] = min(st[i][lg - 1], st[i + len][lg - 1]);
        }
    }
    int query(int l, int r) {
        int lg = __lg(r - l + 1);
        int len = 1 << lg;
        return min(st[l][lg], st[r - len + 1][lg]);
    }
};

signed main() {
    // IO;
    int n;
    cin >> n;
    FOR (i, 1, n) cin >> a[i];
    Sparse_table st(n);
    vector<pii> v;
    FOR (i, 1, n) v.push_back({a[i], i});
    sort(all(v));
    set<pair<int, pii>> pos; 
    int cur = v[0].F * n;
    pos.insert({1, {v[0].F, n}});
    int ans = cur;
    for (auto [val, id] : v) {
        auto it = pos.upper_bound({id, {INT_MAX, INT_MAX}});
        it = prev(it);
        auto [l, p] = *it;
        auto [pre_min, cnt] = p;
        pos.erase(it);
        cur -= pre_min * cnt;
        if (l <= id - 1) {
            pii item1 = {st.query(l, id - 1), id - l};
            cur += item1.F * item1.S;
            pos.insert({l, item1});
        }
        if (id + 1 <= l + cnt - 1) {
            pii item2 = {st.query(id + 1, l + cnt - 1), cnt - 1 - (id - l)};
            cur += item2.F * item2.S;
            pos.insert({id + 1, item2});
        }
        ans = max(ans, cur);
    }
    cout << ans << "\n";
}