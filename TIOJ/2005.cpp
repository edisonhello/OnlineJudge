#include <bits/stdc++.h>
using namespace std;

int n, mod;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

using matrix = vector<vector<int>>;

matrix matmul(const matrix &a, const matrix &b) {
    matrix ret(a.size(), vector<int>(b[0].size(), 0));
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b[0].size(); ++j) {
            for (int k = 0; k < b.size(); ++k) ret[i][j] = add(ret[i][j], mul(a[i][k], b[k][j]));
        }
    }
    return ret;
}

matrix fpow(matrix a, int n) {
    matrix ret(a.size(), vector<int>(a[0].size(), 0));
    for (int i = 0; i < a.size(); ++i) ret[i][i] = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = matmul(ret, a);
        a = matmul(a, a);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    while (cin >> n >> mod) {
        matrix mat(3, vector<int>(1, 0));
        mat[0][0] = 0; mat[1][0] = 0; mat[2][0] = 1;
        for (int k = 1; ; k *= 10) {
            int l = k, r = min(n, k * 10 - 1);
            int f = mul(mat[0][0], mul(k, 10));
            f = add(f, l);
            matrix t(3, vector<int>(3, 0));
            mat = { {f}, {l}, {1} };
            t[0][0] = mul(k, 10); t[0][1] = 1; t[0][2] = 1;
            t[1][0] = 0; t[1][1] = 1; t[1][2] = 1;
            t[2][0] = 0; t[2][1] = 0; t[2][2] = 1;
            t = fpow(t, r - l);
            mat = matmul(t, mat);
            if (r == n) break;
        }
        cout << mat[0][0] << endl;
    }
    return 0;
}
