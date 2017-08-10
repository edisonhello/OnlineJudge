class TwoSat {
    private:
        vector<int> G[maxn << 1];
        bool v[maxn << 1];
        int s[maxn << 1], c;
        bool dfs(int now) {
            if (v[now ^ 1]) return false;
            if (v[now]) return true;
            v[now] = true;
            s[c++] = now;
            for (int u : G[now]) if (!dfs(u)) return false;
            return true;
        }
    public:
        void add_edge(int a, int b) {
            G[a].push_back(b);
        }
        bool solve() {
            for (int i = 0; i < maxn << 1; i += 2) {
                if (!v[i] && !v[i + 1]) {
                    c = 0;
                    if (!dfs(i)) {
                        while (c) v[s[--c]] = false;
                        if (!dfs(i + 1)) return false;
                    }
                }
            }
            return true;
        }
};
