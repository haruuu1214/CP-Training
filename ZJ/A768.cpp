#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

int arr[3005];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;

    int n, i, j, k;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> arr[i];
        v.push_back(arr[i] * arr[i]);
    }
    sort(v.begin(), v.end());

    int cnt = 0;
    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (binary_search(v.begin(), v.end(), arr[i] * arr[i] + arr[j] * arr[j]))
                cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}