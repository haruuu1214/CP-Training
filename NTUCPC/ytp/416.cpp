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

const int N = 1030;
const int mod = 998244353;
int a[N][N];

int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

signed main() {
    IO;
    int n, m;
    cin >> n >> m;
    FOR (i, 1, n) FOR (j, 1, m) cin >> a[i][j];
    auto inside = [&](int x, int y) {
        return (1 <= x && x <= n && 1 <= y && y <= m);
    };
    FOR (i, 1, n) FOR (j, 1, m) {
        int sum = 0;
        for (int k = 0; k < 8; k++)
            if (inside(i + dx[k], j + dy[k]))
                sum += a[i + dx[k]][j + dy[k]];
        cout << sum << " \n"[j == m];
    }
}