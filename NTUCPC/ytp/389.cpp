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

struct RangeSet { // [l, r)
  set<pii> st;
  int cnt = 0;
  void cut(int x) {
    auto it = st.lower_bound({x + 1, -1});
    if (it == st.begin()) return;
    auto [l, r] = *prev(it);
    if (l >= x || x >= r) return;
    st.erase(prev(it));
    st.insert({l, x});
    st.insert({x, r});
  }
  bool inside(int l, int r) {
    // [l, r) is included in st
    auto it = st.lower_bound({l + 1, -1});
    if (it != st.begin() && prev(it)->first <= l && r <= prev(it)->second) return true;
    return false;
  }
  vector<pii> split(int l, int r) {
    // remove and return ranges in [l, r)
    cut(l), cut(r);
    vector<pii> res;
    while (true) {
      auto it = st.lower_bound({l, -1});
      if (it == st.end() || r <= it->first) break;
      cnt -= it->second - it->first;
      res.push_back(*it), st.erase(it);
    }
    return res;
  }
  void insert(int l, int r) {
    // add range [l, r), [l, r) not in st, needed to split(l, r) before
    auto it = st.lower_bound({l, r});
    if (it != st.begin() && prev(it)->second == l) {
      cnt -= prev(it)->second - prev(it)->first;
      l = prev(it)->first, st.erase(prev(it));
    }
    if (it != st.end() && r == it->first) {
      cnt -= it->second - it->first;
      r = it->second, st.erase(it);
    }
    cnt += r - l;
    st.insert({l, r});
  }
  bool count(int x) {
    auto it = st.lower_bound({x + 1, -1});
    return it != st.begin() && prev(it)->first <= x && x < prev(it)->second;
  }
};

const int N = 300005;
const int mod = 998244353;

vector<pair<pii, int>> G[N], G2[N];
vector<RangeSet> res;

void dfs(int v, int l, int r) {
    res[v].split(l, r); res[v].insert(l, r);
    pair<pii, int> p = {{l, -1}, -1};
    int id = lower_bound(G[v].begin(), G[v].end(), p) - G[v].begin();
    while (id < siz(G[v])) {
        auto &[edge, u] = G[v][id]; id += 1;
        auto &[edge_l, edge_r] = edge;
        if (max(l, edge_l) < min(r, edge_r)) break;
        if (u == v) continue;
        if (res[u].inside(l, r) == false)
            dfs(u, max(l, edge_l), min(r, edge_r));
        id += 1;
    }
}

signed main() {
    IO;
    int n, m, k, v, u, l, r;
    cin >> n >> m >> k;
    res.resize(n + 1);
    FOR (i, 1, m) {
        cin >> v >> u >> l >> r;
        if (v == u) continue;
        G2[v].push_back({{l, r + 1}, u});
        G2[u].push_back({{l, r + 1}, v});
    }
    FOR (i, 1, n) {
        sort(all(G2[i]), [&](auto x, auto y) {
            if (x.S != y.S) return x.S < y.S;
            return x.F < y.F;
        });
        for (auto &[edge, u] : G2[i]) {
            auto &[edge_l, edge_r] = edge;
            if (! G[i].empty() && G[i].back().S == u
                 && max(edge_l, G[i].back().F.F) < min(edge_r, G[i].back().F.S)) {
                G[i][siz(G[i]) - 1].F.F = min(G[i][siz(G[i]) - 1].F.F, edge_l);
                G[i][siz(G[i]) - 1].F.S = max(G[i][siz(G[i]) - 1].F.S, edge_r);
            } else {
                G[i].push_back({edge, u});
            }
        }
        sort(all(G[i]));
    }
    dfs(1, 1, k + 1);
    FOR (i, 2, n) cout << res[i].cnt << " \n"[i == n];
}