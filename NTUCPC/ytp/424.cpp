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
const int N = 5005;
const int mod = 998244353;

vector<int> num1, num2;
int getx(int x) {
    return lower_bound(all(num1), x) - num1.begin() + 1;
}
int gety(int x) {
    return lower_bound(all(num2), x) - num2.begin() + 1;
}
pii a[N];
bool mp[N][N], vis[N][N];

signed main() {
    IO;
    int r, c, n, x, y;
    cin >> r >> c >> n;
    FOR (i, 1, n) {
        cin >> x >> y;
        num1.push_back(x);
        num2.push_back(y);
        a[i] = {x, y};
    }
    sort(all(num1)); num1.resize(unique(all(num1)) - num1.begin());
    sort(all(num2)); num2.resize(unique(all(num2)) - num2.begin());
    FOR (i, 1, n) mp[getx(a[i].F)][gety(a[i].S)] = 1;
    for (int i = 1; i <= n; i++) {
        bool can = true;
        for (int j = 1; j <= n; j++) {
            if (mp[i][j]) can = false;
            vis[i][j] |= can;
        }
    }
    for (int i = 1; i <= n; i++) {
        bool can = true;
        for (int j = n; j >= 1; j--) {
            if (mp[i][j]) can = false;
            vis[i][j] |= can;
        }
    }
    for (int j = 1; j <= n; j++) {
        bool can = true;
        for (int i = 1; i <= n; i++) {
            if (mp[i][j]) can = false;
            vis[i][j] |= can;
        }
    }
    for (int j = 1; j <= n; j++) {
        bool can = true;
        for (int i = n; i >= 1; i--) {
            if (mp[i][j]) can = false;
            vis[i][j] |= can;
        }
    }
    bool suc = true;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (! mp[i][j] && ! vis[i][j])
                suc = false;
    if (suc) cout << "yes\n";
    else cout << "no\n";
}