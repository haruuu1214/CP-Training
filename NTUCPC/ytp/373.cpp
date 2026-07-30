#include <bits/stdc++.h>
using namespace std;
struct DSU {
    vector<int> dsu, sz;
    DSU(int _n) : dsu(_n + 1), sz(_n + 1) {
        for (int i = 1; i <= _n; i++) {
            dsu[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x) {
        if (x == dsu[x]) return x;
        return dsu[x] = find(dsu[x]);
    }
    bool merge(int x, int y) {
        int xx = find(x), yy = find(y);
        if (xx == yy) return false;
        if (sz[xx] < sz[yy]) swap(xx, yy);
        dsu[yy] = xx;
        sz[xx] += sz[yy];
        return true;
    }
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, x;
    cin >> n;
    DSU dsu(n);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        dsu.merge(i, x);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (dsu.dsu[i] == i)
            ans += dsu.sz[i] - 1;
    cout << ans;
}