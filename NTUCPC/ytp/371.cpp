#include <bits/stdc++.h>
using namespace std;

int cnt[26];

signed main() {
    int n;
    string a, b;
    cin >> n;
    cin >> a >> b;
    for (char c : a) cnt[c - 'a'] += 1;
    int ans = 0;
    for (char c : b)
        if (cnt[c - 'a']) {
            cnt[c - 'a'] -= 1;
            ans += 1;
        }
    cout << ans;
}