#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, i, tmp;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> tmp;
        if (i != n) {
            cout << (n - i) * tmp << " ";
        }
    }
    cout << "\n";

    return 0;
}