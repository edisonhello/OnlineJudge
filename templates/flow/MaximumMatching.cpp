struct MaximumMatching {
    vector<int> G[maxn], mt;
    int n;
    bitset<maxn> v;
    MaximumMatching(int n): n(n) {
        fill(G, G + maxn, vector<int>());
        v.reset();
    }
    void add_edge(int a, int b) {
        G[a].push_back(b);
    }
    bool dfs(int now) {
        v[now] = true;
        for (int u : G[now]) {
            if (mt[u] == -1 || !v[mt[u]] && dfs(mt[u])) {
                mt[u] = now;
                return true;
            }
        }
        return false;
    }
    int solve() {
        mt.assign(n, -1);
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            memset(v, false, sizeof(v));
            if (dfs(i)) ++ret;
        }
        return ret;
    }
};
