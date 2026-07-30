/**
 * @brief 對答案二分搜
 * 
 * 檢查是否可以組成 x 個學生會
 * ---> 計算符合可能的人數 if sum >= x*k return True
 * ---> 計算方式：組成 x 個學生會 每個組最多提供 x 人
 * 
 */
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int n, k;
int arr[55];

bool check(int x)
{
    int i, sum=0;
    for (i=1;i<=n;i++) {
        sum += min(x, arr[i]);
    }
    if (sum >= x*k) return true;
    return false;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;
    int i;
    for (i=1;i<=n;i++)
        cin >> arr[i];
    
    int l = 0, r = 1e15;
    while (l <= r) {
        int mid = (l+r)/2;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << r << "\n";

    return 0;
}