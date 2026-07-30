#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define siz(x) (int)x.size()
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// ---------------------------------------------

const int N = 15;
const int mod = 998244353;

string dis[N][N];

bool smaller_than(string s1, string s2) {
    int a = siz(s1), b = siz(s2);
    FOR (i, 0, min(a, b) - 1)
        if (s1[i] != s2[i])
            return s1[i] < s2[i];
    return true;
}

signed main() {
    IO;
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    FOR (i, 0, n - 1) cin >> v[i];
    string tmp;
    FOR (i, 0, n + m - 1) tmp += 'z';
    fill(&dis[0][0], &dis[0][0] + N * N, tmp);
    queue<pair<string, pii>> Q;
    dis[0][0] = v[0][0];
    Q.push({dis[0][0], {0, 0}});
    while (! Q.empty()) {
        string str = Q.front().F; pii cur = Q.front().S; Q.pop();
        if (dis[cur.F][cur.S] != str) continue;
        pii nxt1 = {cur.F + 1, cur.S};
        if (nxt1.F < n) {
            if (smaller_than(str + v[nxt1.F][nxt1.S], dis[nxt1.F][nxt1.S])) {
                dis[nxt1.F][nxt1.S] = dis[cur.F][cur.S] + v[nxt1.F][nxt1.S];
                Q.push({dis[nxt1.F][nxt1.S], nxt1});
            }
        }
        pii nxt2 = {cur.F, cur.S + 1};
        if (nxt1.S < m) {
            if (smaller_than(dis[cur.F][cur.S] + v[nxt2.F][nxt2.S], dis[nxt2.F][nxt2.S])) {
                dis[nxt2.F][nxt2.S] = dis[cur.F][cur.S] + v[nxt2.F][nxt2.S];
                Q.push({dis[nxt2.F][nxt2.S], nxt2});
            }
        }
    }
    cout << dis[n - 1][m - 1];
}