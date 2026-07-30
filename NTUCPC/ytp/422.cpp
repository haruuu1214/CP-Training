#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define siz(x) (int)x.size()
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// ---------------------------------------------
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

signed main() {
    IO;
    tree<pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, tree_order_statistics_node_update> bst;
    long long q, k;
    cin >> q >> k;
    long long o, x;
    int cnt = 0;
    while (q--) {
        cin >> o;
        if (o == 1) {
            cin >> x;
            bst.insert({x, cnt});
            cnt += 1;
        } else {
            if (bst.size() < k) {
                cout << -1 << "\n";
                continue;
            }
            auto i = bst.find_by_order(k - 1);
            cout << (*i).first << "\n";
            bst.erase(bst.find(*i));
        }
    }
}
