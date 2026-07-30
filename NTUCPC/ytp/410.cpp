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
    string s;
    cin >> s;
    int n = siz(s);
    int o = 0, a = 0, b = 0, c = 0;
    int id = 0;
    o = s[id] - '0';
    id += 2;
    while (id < n && s[id] != ',') {
        a = a * 10 + (s[id] - '0');
        id += 1;
    }
    id += 1;
    while (id < n && s[id] != ',') {
        b = b * 10 + (s[id] - '0');
        id += 1;
    }
    id += 1;
    while (id < n && s[id] != ',') {
        c = c * 10 + (s[id] - '0');
        id += 1;
    }
    if (o == 1) {
        if (c == 0)
            cout << (int)sqrtl(a * a + b * b) << "\n";
        else if (a == 0)
            cout << (int)sqrtl(c * c - b * b) << "\n";
        else
            cout << (int)sqrtl(c * c - a * a) << "\n";
    } else if (o == 2) {
        if (c == 0)
            cout << 2 * (a - b) << "\n";
        else if (a == 0)
            cout << (c + 2 * b) / 2 << "\n";
        else
            cout << (2 * a - c) / 2 << "\n";
    } else {
        if (c == 0)
            cout << a * b << "\n";
        else if (a == 0)
            cout << c / b << "\n";
        else
            cout << c / a << "\n";
    }
}