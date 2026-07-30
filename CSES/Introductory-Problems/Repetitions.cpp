#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

const int N = 100005;

signed main() {
    string s;
    cin >> s;
    char c = '.';
    int cnt = 0, res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (c != s[i]) {
            res = max(res, cnt);
            c = s[i];
            cnt = 1;
        } else {
            cnt += 1;
        }
    }
    res = max(res, cnt);
    cout << res << "\n";

    return 0;
}