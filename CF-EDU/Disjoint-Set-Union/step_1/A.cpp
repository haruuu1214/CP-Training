#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>

using namespace std;

int dsu[100005];
int n;

void init()
{
    int i;
    for (i=1;i<=n;i++)
        dsu[i] = i;
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
    dsu[x] = y;
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
        cin >> s >> u >> v;
        if (s[0] == 'u')
            merge(u, v);
        else {
            if (find(u) == find(v))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    
    return 0;
}