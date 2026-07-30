// #pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
// #define int long long
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << " "; dbg(b...);}
void ent() {cout << "\n";}

const int mod = 998244353;
// const ll INF = 1e18;
const int INF = 2e9;

/// ------- Initialization End -------

const int N = 1005;

map <int, set<int>> mp;

signed main()
{
    IO
    
    int n, m;
    int v, u;
    bool fg = true;
    cin >> n >> m;
    if (n * (n - 1) / 2 < m) {
        cout << "Yes\n";
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        cin >> v >> u;
        if (v > u)
            swap(v, u);
        if (v == u || (mp.count(v) && mp[v].count(u))) {
            fg = false;
            break;
        }
        mp[v].insert(u);
    }
    cout << (fg ? "yes\n" : "Yes\n");
    
    return 0;
}