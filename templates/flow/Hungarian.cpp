struct Hungarian {
    vector<int> lx, ly, match;
    vector<vector<int>> w;
    int n;
    bitset<maxn> s, t;
    bool dfs(int now) {
        s[now] = true;
        for (int i = 0; i < n; ++i) {
            if (lx[now] + ly[i] == w[now][i] && !t[i]) {
                t[i] = true;
                if (match[i] == -1 || dfs(match[i])) {
                    match[i] = now;
                    return true;
                }
            }
        }
        return false;
    }
    void relabel() {
        int a = inf;
        for (int i = 0; i < n; ++i) if (s[i]) {
            for (int j = 0; j < n; ++j) if (!t[j]) {
                a = min(a, lx[i] + ly[j] - w[i][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (s[i]) lx[i] -= a;
            if (t[i]) ly[i] += a;
        }
    }
    Hungarian(int n): n(n) {
        w.assign(n, vector<int>());
        for (int i = 0; i < n; ++i) w[i].assign(n, 0);
        lx.assign(n, 0); ly.assign(n, 0);
        match.assign(n, -1);
    }
    void add_edge(int a, int b, int c) {
        w[a][b] = c;
    }
    int solve() {
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) lx[i] = max(lx[i], w[i][j]);
        for (int i = 0; i < n; ++i) {
            while (true) {
                s.reset(); t.reset();
                if (dfs(i)) break;
                else relabel();
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) ans += w[match[i]][i];
        return ans;
    }
};
