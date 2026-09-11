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

const int mod = 998244353;
vector<int> v;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 1, b = 0;
    if (s[0] == 'L') {
        cout << -1 << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            if (a % 2 == 1)
                a += 1;
            else if (b % 2 == 1)
                b += 1;
            else {
                v.push_back(-1);
                cout << -1 << '\n'; return;
            }
        } else {
            if (a % 2 == 0)
                a += 1;
            else if (b % 2 == 0)
                b += 1;
            else {
                v.push_back(-1);
                cout << -1 << '\n'; return;
            }
        }
    }
    v.push_back(a);
    cout << a << '\n';
    return;
}

signed main() {
    IO;
    
    int t;
    cin >> t;
    while (t--) solve();
}