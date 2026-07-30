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

const int N = 300005;
const int mod = 998244353;
int a[N];
int par[N];

void solve() {
    int n;
    cin >> n;
    FOR (i, 1, n) cin >> a[i];
    priority_queue<pair<pii, int>, vector<pair<pii, int>>, less<pair<pii, int>>> not_used, used;
    FOR (i, 1, n) not_used.push({{a[i], i}, 0});
    par[not_used.top().F.S] = 0;
    used.push(not_used.top()); not_used.pop();
    int mx = 0;
    while (! used.empty()) {
        pair<pii, int> now = used.top(); used.pop();
        FOR (tt, 1, now.F.F) {
            pair<pii, int> nxt = not_used.top(); not_used.pop();
            nxt.S = now.S + 1;
            mx = max(mx, nxt.S);
            used.push(nxt);
            par[nxt.F.S] = now.F.S;
        }
    }
    cout << mx << "\n";
    FOR (i, 1, n) cout << par[i] << " \n"[i == n];
}

signed main() {
    IO;
    int t;
    cin >> t;
    while (t--) solve();
}