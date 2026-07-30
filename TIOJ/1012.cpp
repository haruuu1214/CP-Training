#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define F first
#define S second
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define loop(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

signed main()
{
    IOS

    int n, m;
    cin >> n >> m;
    int x;

    vector <int> station;

    int id = 0;

    loop(i, 1, n) {
        cin >> x;
        while (id < x)
            station.push_back(++id);
        auto it = find(station.begin(), station.end(), x);
        int pop_amount = (station.end() - it) - 1;
        if (pop_amount > m) {
            cout << "no\n";
            return 0;
        } else {
            station.erase(it);
        }
    }
    cout << "yes\n";
    
    return 0;
}