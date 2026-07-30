#include <bits/stdc++.h>
#define int long long
#define loop(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
using namespace std;
vector <pii> G[100005];
int dis[100005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b, c;
    cin >> n >> m;
    loop(i, 1, m) {
        cin >> a >> b >> c;;
        G[a].push_back({b, c});
    }
    fill(dis, dis + 100005, 1e18);

    priority_queue <pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    dis[1] = 0;
    while (!pq.empty()) {
        int w = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if (dis[v] != w) continue;

        for (pii u : G[v]) {
            if (w + u.second < dis[u.first]) {
                dis[u.first] = w + u.second;
                pq.push({dis[u.first], u.first});
            }
        }
    }

    loop(i, 1, n) cout << dis[i] << " ";
    cout << "\n";
    return 0;
}
