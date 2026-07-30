#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int a[N], b[N];
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    getline(cin, s);
    stringstream ss(s);
    int n = 0, t;
    while (ss >> t) {
        a[n] = t;
        n++;
    }
    reverse(a, a + n);
    for (int i = 0; i <= n - 2; i++) b[i] = a[i + 1] * (i + 1);
    auto geta = [&](double x) {
        double sum = 0, p = 1;
        for (int i = 0; i <= n - 1; i++) {
            sum += p * a[i];
            p *= x;
        }
        return sum;
    };
    auto getb = [&](double x) {
        double sum = 0, p = 1;
        for (int i = 0; i <= n - 2; i++) {
            sum += p * b[i];
            p *= x;
        }
        return sum;
    };
    double x = 0;
    while (fabs(geta(x)) > 0.0001)
        x = x - geta(x) / getb(x);
    cout << fixed << setprecision(2) << x << "\n";
}