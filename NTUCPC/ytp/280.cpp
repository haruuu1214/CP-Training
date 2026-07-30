#include <bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
#define siz(x) (int)x.size()
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// ---------------------------------------------
struct frac {
    int a, b;
    frac(int _a = 0, int _b = 1) : a(_a), b(_b) {
        int g = __gcd(a, b);
        a /= g; b /= g;
        if (b < 0) { a *= -1; b *= -1; }
    }
};
bool operator<(frac x, frac y) { return x.a * y.b < y.a * x.b; }
bool operator==(frac x, frac y) { return x.a * y.b == y.a * x.b; }
frac abs(frac x) { return frac(abs(x.a), abs(x.b)); }
ostream& operator<<(ostream &os, const frac& x) { os << x.a << "/" << x.b; return os; }

signed main() {
    IO;
    auto solve = [&]() {
        int n, a, b, c;
        cin >> n;
        vector<pair<frac, frac>> good, bad;
        FOR (i, 1, n) {
            cin >> a >> b >> c;
            if (a == 0 && b == 0)
                ;
            else if (a == 0) {
                // b * x + c = 0   ===>   x = -c / b
                good.push_back({frac(-c, b), frac()});
            } else {
                int d = b * b - 4 * a * c;
                if (d < 0) {
                    bad.push_back({frac(-b, 2 * a), frac(d, 4 * a * a)});
                } else if (d > 0) {
                    int dd = sqrtl(d);
                    if (dd * dd == d) {
                        good.push_back({frac(-b + dd, 2 * a), frac()});
                        good.push_back({frac(-b - dd, 2 * a), frac()});
                    } else {
                        good.push_back({frac(-b, 2 * a), frac(d, 4 * a * a)});
                        good.push_back({frac(-b, 2 * a), frac(-d, 4 * a * a)});
                    }
                } else {
                    good.push_back({frac(-b, 2 * a), frac()});
                }
            }
        }
        sort(all(good)); good.resize(unique(all(good)) - good.begin());
        sort(all(bad)); bad.resize(unique(all(bad)) - bad.begin());
        int cnt = siz(good) + 2 * siz(bad);
        cout << cnt << "\n";
    };
    int t;
    cin >> t;
    while (t--) solve();
}