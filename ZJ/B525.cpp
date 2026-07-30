#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define matrix array<array<int, 2>, 2>
using namespace std;
const int N = 2;

const int MOD = 100000007;

matrix mul(matrix a, matrix b) {
    matrix c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            c[i][j] = 0;
            for (int k = 0; k < N; k++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= MOD;
            }
        }
    }
    return c;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, k;

    while (cin >> a >> b >> k) {
        matrix A, F;

        A[0][0] = 1;
        A[0][1] = 0;
        A[1][0] = 0;
        A[1][1] = 1;

        F[0][0] = 0;
        F[0][1] = 1;
        F[1][0] = 1;
        F[1][1] = 1;

        while (k > 0) {
            if (k & 1)
                A = mul(A, F);
            F = mul(F, F);
            k >>= 1;
        }

        int ans = (a * (A[0][0] + A[1][0])) % MOD + (b * (A[0][1] + A[1][1])) % MOD;
        ans %= MOD;
        cout << ans << "\n";
    }

    return 0;
}