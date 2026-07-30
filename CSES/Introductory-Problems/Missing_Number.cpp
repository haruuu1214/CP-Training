#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 100005;

signed main() {
    int n;
    cin >> n;
    vector <int> v(n - 1);
    for (int i = 0; i < n - 1; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 1; i++)
        if (v[i] != i + 1) {
            cout << i + 1 << "\n";
            return 0;
        }
    cout << n << "\n";
    
    return 0;
}