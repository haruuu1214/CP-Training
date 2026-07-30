#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 100005;

signed main() {
    int n;
    cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans += max(0ll, v[i - 1] - v[i]);
        v[i] = max(v[i], v[i - 1]);
    }
    cout << ans << "\n";
    
    return 0;
}