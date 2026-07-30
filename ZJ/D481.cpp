#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
#define matrix array<array<int, N>, N>
const int N = 100;

matrix mul(matrix A, matrix B, int a, int b, int c) {
    matrix C;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < c; j++) {
            C[i][j] = 0;
            for (int k = 0; k < b; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
    return C;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d;

    matrix A, B, C;

    while (cin >> a >> b >> c >> d) {
        if (b != c) {
            cout << "Error\n";
            continue;
        }

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                cin >> A[i][j];
            }
        }

        for (int i = 0; i < c; i++) {
            for (int j = 0; j < d; j++) {
                cin >> B[i][j];
            }
        }

        C = mul(A, B, a, b, d);

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < d; j++) {
                cout << C[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}