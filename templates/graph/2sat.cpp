struct TwoSat {
    vector<int> G[maxn << 1];
    bitset<maxn << 1> v;
    vector<int> s;
    int c;
    bool dfs(int now) {
        if (v[now ^ 1]) return false;
        if (v[now]) return true;
        v[now] = true;
        s[c++] = now;
        for (int u : G[now]) if (!dfs(u)) return false;
        return true;
    }
    TwoSat() {
        s.assign(maxn << 1, 0);
        v.reset();
    }
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
