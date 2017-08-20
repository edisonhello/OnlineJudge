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
