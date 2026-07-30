#include <bits/stdc++.h>
using namespace std;

const int N = 9;

int a[N][N];
int dx[N], dy[N], d[3][3];
int n;

bool check(int x, int y, int num) {
    return (((dx[x] >> num & 1) == 0) && ((dy[y] >> num & 1) == 0)
      && ((n == 3 && (d[x / 3][y / 3] >> num & 1) == 0) || (n == 2 && (d[x / 2][y / 2] >> num & 1) == 0)));
}

void put_tag(int x, int y, int num) {
    a[x][y] = num;
    dx[x] ^= 1 << num;
    dy[y] ^= 1 << num;
    if (n == 3) d[x / 3][y / 3] ^= 1 << num;
    if (n == 2) d[x / 2][y / 2] ^= 1 << num;
    return;
}

void undo_tag(int x, int y, int num) {
    a[x][y] = -1;
    dx[x] ^= 1 << num;
    dy[y] ^= 1 << num;
    if (n == 3) d[x / 3][y / 3] ^= 1 << num;
    if (n == 2) d[x / 2][y / 2] ^= 1 << num;
    return;
}

void dfs(int x, int y) {
    if (x == n * n - 1 && y == n * n) {
        if (n == 3) {
            for (int i = 0; i < n * n; i++) {
                for (int j = 0; j < n * n; j++)
                    cout << a[i][j] + 1;
                cout << "\n";
            }
        } else {
            for (int i = 0; i < n * n; i++) {
                for (int j = 0; j < n * n; j++)
                    cout << (char)('A' + a[i][j]);
                cout << "\n";
            }
        }
        exit(0);
    }
    if (y == n * n) { dfs(x + 1, 0); return; }
    if (a[x][y] != -1) { dfs(x, y + 1); return; }
    for (int i = 0; i < n * n; i++) {
        if (check(x, y, i)) {
            put_tag(x, y, i);
            dfs(x, y + 1);
            undo_tag(x, y, i);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    fill(&a[0][0], &a[0][0] + N * N, -1);
    char ch;
    string s;
    getline(cin, s);
    n = s[0] - '0';
    vector<string> mp(n * n);
    for (int i = 0; i < n * n; i++) {
        getline(cin, mp[i]);
        for (int j = 0; j < n * n; j++) {
            ch = mp[i][j];
            if (ch == '#' || ch == '?') ;
            else {
                if (ch == 'A') put_tag(i, j, 0);
                else if (ch == 'B') put_tag(i, j, 1);
                else if (ch == 'C') put_tag(i, j, 2);
                else if (ch == 'D') put_tag(i, j, 3);
                else put_tag(i, j, ch - '0' - 1);
            }
        }
    }
    dfs(0, 0);
    cout << -1 << "\n";
}