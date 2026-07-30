#include <bits/stdc++.h>
using namespace std;

inline int G(int x) {
    if (x == 6 || x == 15 || x == 120) return 2;
    if (15 < x && x < 120) return x & 1;
    return (x + 1) & 1;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x, res = 0;
        cin >> n;
        while (n--) {
            cin >> x;
            res ^= G(x);
        }
        cout << (res == 0 ? "TT" : "MM") << "\n";
    }
/*
    vector<int> prexor;
    int cnt = 2, lst = 0;
    prexor.push_back(0); prexor.push_back(0);
    for (int i = 2; i <= 1000000000; i++) {
        int res;
        if (i == cnt * (cnt + 1) / 2) {
            vector<int> v = {prexor[cnt], lst};
            sort(all(v));
            if (v[0] == 0 && v[1] == 0)
                res = 1;
            else if (v[0] == 0 && v[1] == 1)
                res = 2;
            else if (v[0] == 0 && v[1] == 2)
                res = 1;
            else if (v[0] == 0 && v[1] == 3)
                res = 1;
            else
                res = 0;
            cnt += 1;
        } else {
            if (lst == 0)
                res = 1;
            else
                res = 0;
        }
        if (siz(prexor) < 50000) prexor.push_back(prexor.back() ^ res);
        lst = res;
        // cout << res << " ";
        // if (res == 2) cout << i << " ";
        // if (i == 1 || i == 7 || i == 16 || i == 121)
        //    cout << i << ": " << res << "\n";
    }
*/
}