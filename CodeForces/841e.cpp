#include <bits/stdc++.h>
using namespace std;

const int maxn = 300 + 10, mod = 1e9 + 7;

template <typename T> class Matrix {
    public:
        int n, m, mod;
        vector<vector<T>> mat;
        Matrix(int n, int m, int mod=0, bool I=false): n(n), m(m), mod(mod) {
            mat.resize(n);
            for (int i = 0; i < n; ++i) mat[i].resize(m);
            if (!I) return;
            for (int i = 0; i < n; ++i) mat[i][i] = 1;
        }
        Matrix operator+(const Matrix& rhs) const {
            Matrix ret(n, m, mod);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    ret.mat[i][j] = mat[i][j] + rhs.mat[i][j];
                    if (mod) ret.mat[i][j] %= mod;
                }
            }
            return ret;
        }
        Matrix operator-(const Matrix& rhs) const {
            Matrix ret(n, m, mod);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    ret.mat[i][j] = mat[i][j] - rhs.mat[i][j];
                    if (mod) {
                        ret.mat[i][j] %= mod;
                        ret.mat[i][j] += mod;
                        ret.mat[i][j] %= mod;
                    }
                }
            }
            return ret;
        }
        Matrix operator*(const Matrix& rhs) const {
            Matrix ret(n, rhs.m, mod);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < rhs.m; ++j) {
                    for (int k = 0; k < m; ++k) {
                        if (mod) ret.mat[i][j] = (ret.mat[i][j] + mat[i][k] * rhs.mat[k][j] % mod) % mod;
                        else ret.mat[i][j] += mat[i][k] * rhs.mat[k][j];
                    }
                }
            }
            return ret;
        }
};

int a[maxn];
multiset<int> ms;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    Matrix<long long> m(n + 1, n + 1, mod);
    for (int i = 1; i <= n; ++i) cin >> a[i], ms.insert(a[i]);
    int c = 1;
    for (auto i = ms.begin(); i != ms.end(); ++i) {
        auto j = i; ++j; int d = c + 1;
        for (auto j = ms.begin(); j != ms.end(); ++j) {
            long long k = (long long)i->first * (long long)j->first;
            if ((int)sqrt(k) == sqrt(k)) {
                m.mat[c][d] = 1;
            }
            ++d;
        }
        ++c;
    }
    int nn = n;
    Matrix<long long> ret(n + 1, n + 1, mod, true);
    for (; nn; nn >>= 1) {
        if (nn & 1) ret = ret * m;
        m = m * m;
    }
    for (int i = 1; i <= ms.size(); ++i) {
        for (int j = 1; j <= ms.size(); ++j) cout << m.mat[i][j] << ' '; cout << endl;
    }
    return 0;
}
