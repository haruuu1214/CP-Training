// #pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
#define int long long
// #define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << " "; dbg(b...);}
void ent() {cout << "\n";}

const int mod = 998244353;
// const int mod = 1e9 + 7;
// const int INF = 2e9;
const int INF = 1e18;

/// ------- Initialization End -------

const int N = 100005;

map <string, string> name;
map <string, string> dead;

signed main() {
    IO;
    
    string a, b, c;
    while (cin >> a) {
        if (a[0] == 'a') {
            cin >> b >> c;
            name[b] = c;
            dead[c] = b;
        } else if (a[0] == 'c') {
            cin >> b;
            if (b[0] == 'n') {
                string tmp = b.substr(1, b.size());
                if (name.count(tmp))
                    cout << tmp << " " << name[tmp] << "\n";
                else
                    cout << "Not found.\n";
            } else {
                string tmp = b.substr(1, b.size());
                if (dead.count(tmp))
                    cout << dead[tmp] << " " << tmp << "\n";
                else
                    cout << "Not found.\n";
            }
        } else {
            cin >> b;
            if (b[0] == 'n') {
                string nm = b.substr(1, b.size());
                string de = name[nm];
                name.erase(name.find(nm));
                dead.erase(dead.find(de));
            } else {
                string de = b.substr(1, b.size());
                string nm = dead[de];
                name.erase(name.find(nm));
                dead.erase(dead.find(de));
            }
        }
    }
    
    return 0;
}