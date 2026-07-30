#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define F first
#define S second
using namespace std;
using pii = pair<int, int>;


signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    cout << 2 * n * n + 1 << "\n";
    FOR (i, 0, n - 1) FOR (j, 0, n - 1) cout << i << " " << j << " ";
    cout << 0 << "\n";
}
