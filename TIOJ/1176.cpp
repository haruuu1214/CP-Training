// #pragma GCC optimize("Ofast,unroll-loops,O3")
#include <bits/stdc++.h>
// #define int long long
// #define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
void dbg() {;}
template<class T, class ...U>
void dbg(T a, U ...b) {cout << a << " "; dbg(b...);}
void ent() {cout << "\n";}
/// ------- Initialization End -------

const int N = 1000005;
int a[N];
int ans[N];

signed main() {
    IO;
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    ans[n] = n;
    deque<int> dq;
    dq.push_front(n);
    for (int i = n - 1; i >= 1; i--) {
        while (!dq.empty() && a[i] > a[dq.front()])
            dq.pop_front();
        ans[i] = (dq.empty() ? n : dq.front());
        dq.push_front(i);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] - i << "\n";


    return 0;
}