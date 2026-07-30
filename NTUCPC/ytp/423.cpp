#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define siz(x) (int)x.size()
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// ---------------------------------------------

const int N = 6;

int a[N][N];
bool must_one[N][N], mp[N][N];
bool l[N][N], r[N][N], u[N][N], d[N][N];
bool row[N], col[N]; // i , j

vector <int> G[4 * N];

struct Matching {
    int n;
    vector<bool> vis; vector<int> match;
    Matching(int _n) : n(_n), vis(_n + 1), match(_n + 1, -1) {}
    bool dfs(int v) {
        vis[v] = true;
        for (int u : G[v]) {
            if (match[u] == -1 || (!vis[match[u]] && dfs(match[u]))) {
                match[u] = v;
                return true;
            }
        }
        return false;
    }
    int solve() {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vis.assign(n + 1, 0);
            if (dfs(i))
                ans++;
        }
        return ans;
    }
};

signed main() {
    IO;
    char ch;
    int n = 6;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> ch;
            if (ch == '#') a[i][j] = 1;
        }
    
    for (int i = 0; i < n; i++) {
        bool pass = true;
        for (int j = 0; j < n; j++) {
            mp[i][j] = (mp[i][j] | (pass &= !a[i][j]));
            l[i][j] = pass;
        }
    }
    for (int i = 0; i < n; i++) {
        bool pass = true;
        for (int j = n - 1; j >= 0; j--) {
            mp[i][j] = (mp[i][j] | (pass &= !a[i][j]));
            r[i][j] = pass;
        }
    }
    for (int j = 0; j < n; j++) {
        bool pass = true;
        for (int i = 0; i < n; i++) {
            mp[i][j] = (mp[i][j] | (pass &= !a[i][j]));
            u[i][j] = pass;
        }
    }
    for (int j = 0; j < n; j++) {
        bool pass = true;
        for (int i = n - 1; i >= 0; i--) {
            mp[i][j] = (mp[i][j] | (pass &= !a[i][j]));
            d[i][j] = pass;
        }
    }
    bool res = true;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (! a[i][j] && ! mp[i][j]) res = false;
    if (res == false) {
        cout << -1 << "\n";
        return 0;
    }
    int msk = 0;
    for (int i = 0; i < n; i++)
        if (l[i][n - 1] && ! a[i][n - 1]) {
            row[i] = true;
            msk ^= (1 << i);
        }
    for (int j = 0; j < n; j++)
        if (u[n - 1][j] && ! a[n - 1][j]) {
            col[j] = true;
            msk ^= (1 << (n + j));
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (row[i] && col[j])
                must_one[i][j] = true;
    int ans = INT_MAX;
    for (int s = msk; ; s = (s - 1) & msk) {
        bool fail = false;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (must_one[i][j] && ((s >> i & 1) == 0) && ((s >> (n + j) & 1) == 0))
                    fail = true;
        if (fail && ! s) break;
        if (fail) continue;
        vector<vector<bool>> cur(n, vector<bool>(n, 0));
        vector<int> op1, op2, op3, op4;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j]) continue;
                if ((s >> i & 1) || (s >> (n + j) & 1)) {
                    cur[i][j] = true;
                    continue;
                }
                int choose = 0;
                if ((msk >> i & 1) == 0)
                    if (l[i][j] || r[i][j])
                        choose += 1;
                if ((msk >> (n + j) & 1) == 0)
                    if (u[i][j] || d[i][j])
                        choose += 1;
                if (choose == 1) {
                    if ((msk >> i & 1) == 0) if (l[i][j]) op1.push_back(i);
                    if ((msk >> i & 1) == 0) if (r[i][j]) op2.push_back(i);
                    if ((msk >> (n + j) & 1) == 0) if (u[i][j]) op3.push_back(j);
                    if ((msk >> (n + j) & 1) == 0) if (d[i][j]) op4.push_back(j);
                }
                if (choose == 0) fail = true;
            }
        }
        if (fail && ! s) break;
        if (fail) continue;
        sort(all(op1)); op1.resize(unique(all(op1)) - op1.begin());
        sort(all(op2)); op2.resize(unique(all(op2)) - op2.begin());
        sort(all(op3)); op3.resize(unique(all(op3)) - op3.begin());
        sort(all(op4)); op4.resize(unique(all(op4)) - op4.begin());
        int res = __builtin_popcount(s) + siz(op1) + siz(op2) + siz(op3) + siz(op4);
        for (int i : op1) {
            bool pass = true;
            for (int j = 0; j < n; j++) cur[i][j] = (cur[i][j] | (pass &= !a[i][j]));
        }
        for (int i : op2) {
            bool pass = true;
            for (int j = n - 1; j >= 0; j--) cur[i][j] = (cur[i][j] | (pass &= !a[i][j]));
        }
        for (int j : op3) {
            bool pass = true;
            for (int i = 0; i < n; i++) cur[i][j] = (cur[i][j] | (pass &= !a[i][j]));
        }
        for (int j : op4) {
            bool pass = true;
            for (int i = n - 1; i >= 0; i--) cur[i][j] = (cur[i][j] | (pass &= !a[i][j]));
        }
        fill(G, G + 4 * N, vector<int>());
        Matching match(4 * n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (cur[i][j] || a[i][j]) continue;
                vector<int> choice;
                if ((msk >> i & 1) == 0) {
                    if (l[i][j]) choice.push_back(i);
                    if (r[i][j]) choice.push_back(2 * n + i);
                }
                if ((msk >> (n + j) & 1) == 0) {
                    if (u[i][j]) choice.push_back(n + j);
                    if (d[i][j]) choice.push_back(3 * n + j);
                }
                G[choice[0]].push_back(choice[1]);
            }
        res += match.solve();
        ans = min(ans, res);
        if (! s) break;
    }
    cout << ans;
}
/*
    0  1  2  3  4  5 
 6                    18
 7                    19
 .                    .
 .                    .
 .                    .
11                    23
   12 13 14 15 16 17
*/