#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
vector <int> vec;
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n,k,i,tmp,target;
    cin >> n >> k;
    for (i=1;i<=n;i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }
    for (i=1;i<=k;i++) {
        cin >> target;
        if (binary_search(vec.begin(), vec.end(), target))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}