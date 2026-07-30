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

const int mod = 998244353;

signed main() {
    IO;
    double v1 = 0, v2 = 0, th_ad = 0, be_ad = 0;
    string st;
    cin >> st;
    int id = 0;
    while (id < siz(st) && st[id] != '.') {
        v1 = v1 * 10 + (double)(st[id] - '0');
        id += 1;
    }
    id += 1;
    v1 = v1 + 0.1 * (double)(st[id] - '0');
    id += 1;
    v1 = v1 + 0.01 * (double)(st[id] - '0');
    id += 1; // ','
    id += 1;

    while (id < siz(st) && st[id] != '.') {
        v2 = v2 * 10 + (double)(st[id] - '0');
        id += 1;
    }
    id += 1;
    v2 = v2 + 0.1 * (double)(st[id] - '0');
    id += 1;
    v2 = v2 + 0.01 * (double)(st[id] - '0');
    id += 1; // ','
    id += 1;

    while (id < siz(st) && st[id] != '.') {
        th_ad = th_ad * 10 + (double)(st[id] - '0');
        id += 1;
    }
    id += 1;
    th_ad = th_ad + 0.1 * (double)(st[id] - '0');
    id += 1;
    th_ad = th_ad + 0.01 * (double)(st[id] - '0');
    id += 1; // ','
    id += 1;

    while (id < siz(st) && st[id] != '.') {
        be_ad = be_ad * 10 + (double)(st[id] - '0');
        id += 1;
    }
    id += 1;
    be_ad = be_ad + 0.1 * (double)(st[id] - '0');
    id += 1;
    be_ad = be_ad + 0.01 * (double)(st[id] - '0');

    double th = atan(v1), s = sqrtl(v1 * v1 + 1);
    double be = atan(v2 / s);
    double t = sqrtl(v2 * v2 + s * s);
    th = th + th_ad;
    be = be + be_ad;
    v2 = t * sin(be);
    s = t * cos(be);
    v1 = s * sin(th);
    cout << fixed << setprecision(2) << t << ',' << v1 << ',' << v2 << "\n";
}