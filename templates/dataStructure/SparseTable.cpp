struct SparseTable {
    vector<vector<int>> st;
    SparseTable() {}
    SparseTable(int n, int arr[]) {
        st.resize(lg);
        for (int i = 0; i < lg; ++i) st[i].resize(maxn);
        for (int i = 0; i < n; ++i) st[0][i] = arr[i];
        for (int i = 1; (1 << i) <= n; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) {
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            } 
        }
    }
    int query(int l, int r) {
        int p = 31 - __builtin_clz(r - l + 1);
        return min(st[p][l], st[p][r - (1 << p) + 1]);
    }
};
