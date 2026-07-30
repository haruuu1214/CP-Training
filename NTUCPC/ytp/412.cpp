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

const int N = 15;
int a[N];

signed main() {
    IO;
    string str;
    int n, m, s, x;
    cin >> n;
    int school_cnt = 0;
    int ans = 0;
    FOR (i, 1, n) {
        int res = 0;
        int bad_cnt = 0;
        cin >> m;
        FOR (j, 1, m) {
            bool class_bad = 0;
            cin >> s;
            FOR (k, 1, s) {
                cin >> str;
                if (str == "11") {
                    bad_cnt += 1;
                    class_bad = 1;
                }
            }
            if (class_bad) res += s;
            a[i] += s;
        }
        if (bad_cnt < 2)
            ans += res;
        else {
            ans += a[i];
            school_cnt += 1;
        }
    }
    if (school_cnt * 3 >= n) {
        int sum = 0;
        FOR (i, 1, n) sum += a[i];
        cout << sum << "\n";
    } else {
        cout << ans << "\n";
    }
}