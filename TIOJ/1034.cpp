#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int n;
int arr[25][25];
int dp[2][22][22][22][22];

bool inside(int x, int y)
{
    if (1 <= x && x <= n && 1 <= y && y <= n)
        return 1;
    else
        return 0;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q, i, j;
    cin >> n;
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
            cin >> arr[i][j];

    fill(&dp[0][0][0][0][0], &dp[0][0][0][0][0] + 2*22*22*22*22, 1e18);
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
            dp[0][i][j][i][j] = arr[i][j], dp[1][i][j][i][j] = 0;

    for (i=1; i<=n; i++) {
        for (j=1; j<=n; j++) {
            if (inside(i+1, j)) {
                dp[0][i][j][i+1][j] = arr[i][j] + arr[i+1][j];
                dp[1][i][j][i+1][j] = min(arr[i][j], arr[i+1][j]);
            }
            if (inside(i-1, j)) {
                dp[0][i][j][i-1][j] = arr[i][j] + arr[i-1][j];
                dp[1][i][j][i-1][j] = min(arr[i][j], arr[i-1][j]);
            }
            if (inside(i, j+1)) {
                dp[0][i][j][i][j+1] = arr[i][j] + arr[i][j+1];
                dp[1][i][j][i][j+1] = min(arr[i][j], arr[i][j+1]);
            }
            if (inside(i, j-1)) {
                dp[0][i][j][i][j-1] = arr[i][j] + arr[i][j-1];
                dp[1][i][j][i][j-1] = min(arr[i][j], arr[i][j-1]);
            }
        }
    }


    int ix, iy, jx, jy, kx, ky;
    for (kx=1; kx<=n; kx++) { for (ky=1; ky<=n; ky++) {
        for (ix=1; ix<=n; ix++) { for (iy=1; iy<=n; iy++) {
            for (jx=1; jx<=n; jx++) { for (jy=1; jy<=n; jy++) {
                dp[0][ix][iy][jx][jy] = min({
                    dp[0][ix][iy][jx][jy],
                    dp[0][ix][iy][kx][ky] + dp[0][kx][ky][jx][jy] - arr[kx][ky]
                });
                dp[1][ix][iy][jx][jy] = min({
                    dp[1][ix][iy][jx][jy],
                    dp[1][ix][iy][kx][ky] + dp[0][kx][ky][jx][jy] - arr[kx][ky],
                    dp[0][ix][iy][kx][ky] + dp[1][kx][ky][jx][jy] - arr[kx][ky],
                    dp[0][ix][iy][kx][ky] + dp[0][kx][ky][jx][jy] - arr[kx][ky] - arr[kx][ky]
                });
            }}
        }}
    }}

    int a, b, c, d;
    cin >> q;
    while (q--) {
        cin >> a >> b >> c >> d;
        cout << dp[1][a][b][c][d] << "\n";
    }

    return 0;
}