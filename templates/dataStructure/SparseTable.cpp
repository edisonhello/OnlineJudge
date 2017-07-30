template <typename T> SparseTable {
    private:
        T st[lg][maxn];
        int n;
    public:
        SparseTable(int n, T *arr): n(n) {
            for (int i = 0; i < n; ++i) st[0][i] = T[i];
            for (int i = 1; (1 << i) <= n; ++i) {
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
        SparseTable() {}
        T query(int l, int r) {
            int p = 31 - __bulitin_clz(r - l + 1);
            return min(st[p][l], st[p][r - (1 << p) + 1]);
        }
};
