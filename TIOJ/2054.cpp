// #pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
// #define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << " "; dbg(b...);}
void ent() {cout << "\n";}

const int mod = 998244353;
// const int mod = 1e9 + 7;
// const int INF = 2e9;
const int INF = 1e18;

/// ------- Initialization End -------

const int N = 100005;

signed main() {
    IO;
    
    int n, h, w;
    cin >> n >> w >> h;

    vector<pii> v(n);
    vector<int> px;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        px.push_back(v[i].first);
    }
    sort(px.begin(), px.end());
    px.resize(unique(px.begin(), px.end()) - px.begin());
    sort(v.begin(), v.end(), [&](pii p, pii q) {
        return p.second < q.second;
    });
    int ans = 0;
    for (int L : px) {
        int R = L + h;
        deque<int> Y;
        for (auto &[x, y] : v) {
            if (L <= x && x <= R) {
                while (!Y.empty() && Y.front() < y - w)
                    Y.pop_front();
                Y.push_back(y);
                ans = max(ans, (int)Y.size());
            }
        }
    }
    cout << ans << "\n";
    
    return 0;
}