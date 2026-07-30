#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    string s;
    char ch;
    int total;
    while (cin >> s) {
        ch = s[0];
        if (ch == 'A')
            total = 1;
        else if (ch == 'B')
            total = 10;
        else if (ch == 'C')
            total = 19;
        else if (ch == 'D')
            total = 28;
        else if (ch == 'E')
            total = 37;
        else if (ch == 'F')
            total = 46;
        else if (ch == 'G')
            total = 55;
        else if (ch == 'H')
            total = 64;
        else if (ch == 'I')
            total = 39;
        else if (ch == 'J')
            total = 73;
        else if (ch == 'K')
            total = 82;
        else if (ch == 'L')
            total = 2;
        else if (ch == 'M')
            total = 11;
        else if (ch == 'N')
            total = 20;
        else if (ch == 'O')
            total = 48;
        else if (ch == 'P')
            total = 29;
        else if (ch == 'Q')
            total = 38;
        else if (ch == 'R')
            total = 47;
        else if (ch == 'S')
            total = 56;
        else if (ch == 'T')
            total = 65;
        else if (ch == 'U')
            total = 74;
        else if (ch == 'V')
            total = 83;
        else if (ch == 'W')
            total = 21;
        else if (ch == 'X')
            total = 3;
        else if (ch == 'Y')
            total = 12;
        else if (ch == 'Z')
            total = 30;
        total += (s[9] - '0') * 1 + (s[8] - '0') * 1 + (s[7] - '0') * 2 + (s[6] - '0') * 3 + (s[5] - '0') * 4 + (s[4] - '0') * 5 + (s[3] - '0') * 6 + (s[2] - '0') * 7 + (s[1] - '0') * 8;
        if (total % 10 == 0)
            printf("real\n");
        else
            printf("fake\n");
    }
    return 0;
}