#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 100005;

signed main() {
    int n;
    cin >> n;
    cout << n << " ";
    while (n != 1) {
        if (n % 2)
            n = 3 * n + 1;
        else
            n /= 2;
        cout << n << " ";
    }
    
    return 0;
}