#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 100005;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        int layer = max(x, y);
        int pre = (layer - 1) * (layer - 1) + 1;
        int lst = layer * layer;
        if (layer % 2) {
            if (layer == x) {
                cout << pre + y - 1 << "\n";
            } else {
                cout << lst - x + 1 << "\n";
            }
        } else {
            if (layer == x) {
                cout << lst - y + 1 << "\n";
            } else {
                cout << pre + x - 1 << "\n";
            }
        }
    }
    
    return 0;
}