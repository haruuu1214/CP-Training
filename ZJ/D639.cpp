#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define matrix array<array<int, N>, N>
using namespace std;
const int N = 3;
const int MOD = 10007;

matrix mul(matrix A, matrix B) {
    matrix C;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= MOD;
            }
        }
    }
    return C;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    n -= 3;

    matrix A, F;

    A[0][0] = 1;
    A[0][1] = 0;
    A[0][2] = 0;
    A[1][0] = 0;
    A[1][1] = 1;
    A[1][2] = 0;
    A[2][0] = 0;
    A[2][1] = 0;
    A[2][2] = 1;

    F[0][0] = 1;
    F[0][1] = 1;
    F[0][2] = 1;
    F[1][0] = 1;
    F[1][1] = 0;
    F[1][2] = 0;
    F[2][0] = 0;
    F[2][1] = 1;
    F[2][2] = 0;

    while (n > 0) {
        if (n & 1)
            A = mul(A, F);
        F = mul(F, F);
        n >>= 1;
    }

    cout << (A[0][0] + A[0][1] + A[0][2]) % MOD << "\n";

    return 0;
}