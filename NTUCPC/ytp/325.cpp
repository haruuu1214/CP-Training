#include <bits/stdc++.h>
using namespace std;

signed main() {
    string s;
    cin >> s;
    int x = 0, y = 0;
    for (char c : s) {
        if (c == 'A') x += 1, y += 1;
        if (c == 'B') x += 1;
        if (c == 'C') y -= 1;
        if (c == 'D') x -= 1, y -= 1;
        if (c == 'E') x -= 1;
        if (c == 'F') y += 1;
    }
    if (x <= 0 && y <= 0) x *= -1, y *= -1;
    if (x >= 0 && y >= 0) {
        int d = abs(min(x, y));
        x -= d; y -= d;
        cout << d + x + y << "\n";
    } else {
        cout << abs(x) + abs(y) << "\n";
    }
}