struct HeavyLightDecomp {
    vector<int> G[maxn];
    vector<int> tin, top, dep, maxson, sz, p;
    int n, t;
    void dfs(int now, int fa, int d) {
        dep[now] = d;
        maxson[now] = -1;
        sz[now] = 1;
        p[now] = fa;
        for (int u : G[now]) if (u != fa) {
            dfs(u, now, d + 1);
            sz[now] += sz[u];
            if (maxson[now] == -1 || sz[u] > sz[maxson[now]]) maxson[now] = u;
        }
    }
    void link(int now, int tp) {
        top[now] = tp;
        tin[now] = ++t;
        if (maxson[now] == -1) return;
        link(maxson[now], tp);
        for (int u : G[now]) if (u != p[now]) {
            if (u == maxson[now]) continue;
            link(u, u);
        }
    }
    HeavyLightDecomp(int n): n(n) {
        t = 0;
        tin.assign(n, 0); top.assign(n, 0); dep.assign(n, 0);
        maxson.assign(n, 0); sz.assign(n, 0); p.assign(n, 0);
    }
    void add_edge(int a, int b) {
        G[a].push_back(b);
        G[b].push_back(a);
    }
    void build() {
        dfs(0, -1, 0);
        link(0, 0);
    }
    int lca(int a, int b) {
        int ta = top[a], tb = top[b];
        while (ta != tb) {
            if (dep[ta] < dep[tb]) {
                swap(ta, tb); swap(a, b);
            }
            a = p[ta]; ta = top[a];
        }
        if (a == b) return a;
        return dep[a] < dep[b] ? a : b;
    }
    vector<pair<int, int>> get_path(int a, int b) {
        int ta = top[a], tb = top[b];
        vector<pair<int, int>> ret;
        while (ta != tb) {
            if (dep[ta] < dep[tb]) {
                swap(ta, tb); swap(a, b);
            }
            ret.push_back(make_pair(tin[ta], tin[a]));
            a = p[ta]; ta = top[a];
        }
        ret.push_back(make_pair(min(tin[a], tin[b]), max(tin[a], tin[b])));
        return ret;
    }
};
