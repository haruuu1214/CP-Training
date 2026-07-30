#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>

using namespace std;

int dsu[300005];
pii num[300005];
int sz[300005];
int n;

void init()
{
    int i;
    for (i=1;i<=n;i++) {
        dsu[i] = i;
        sz[i] = 1;
        num[i].first = i;
        num[i].second = i;
    }
    return;
}

int find(int node)
{
    if (dsu[node] == node) return node;

    dsu[node] = find(dsu[node]);
    return dsu[node];
}

void merge(int a, int b)
{
    int x = find(dsu[a]);
    int y = find(dsu[b]);
    if (x == y)
        return;
    dsu[x] = y;
    sz[y] += sz[x];
    num[y].first = min(num[x].first, num[y].first);
    num[y].second = max(num[x].second, num[y].second);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> n >> q;

    init();
    string s;
    int u,v;
    while (q--) {
        cin >> s;
        if (s[0] == 'u') {
            cin >> u >> v;
            merge(u, v);
        } else {
            cin >> u;
            int idx = find(u);
            cout << num[idx].first << " " << num[idx].second << " " << sz[idx] << "\n";
        }
    }
    
    return 0;
}