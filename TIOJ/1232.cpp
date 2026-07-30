// #pragma GCC optimize("Ofast, unroll-loops, O3")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define IO ios::sync_with_stdio(0), cin.tie(0)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
using namespace std;
void dout() {;}
template<class T, class ...U>
void dout(T a, U ...b) {cout << a << (sizeof...(b) ? ", " : " "); dout(b...);}
void entr() {cout << "\n";}

const int mod = 998244353;
// const int mod = 1e9 + 7;
const int INF = 1e18;
/// ------- Initialization End -------

const int N = 15;
int n, k;
vector<int> v;
bool vis[N];

void dfs(int i, int res) {
    if (i == k) {
        v.push_back(res);
        return;
    }
    for (int j = 0; j < n; j++)
        if (! vis[j]) {
            vis[j] = true;
            dfs(i + 1, res * 10 + j);
            vis[j] = false;
        }
}

signed main() {
    IO;
    
    cin >> n >> k;
    dfs(0, 0);
    sort(all(v), greater<int>());
    cout << v[min((int)v.size() - 1, n + k - 1)] << "\n";

    return 0;
}