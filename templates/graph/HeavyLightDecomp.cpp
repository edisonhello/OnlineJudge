class HeavyLightDecomp {
    private:
        vector<int> G[maxn];
        int tin[maxn], top[maxn], dep[maxn], maxson[maxn], sz[maxn], p[maxn], rev[maxn << 1], n, clk;
        void dfs(int now, int fa, int d) {
            dep[now] = d;
            maxson[now] = -1;
            sz[now] = 1;
            p[now] = fa;
            tin[now] = ++clk;
            for (int u : G[now]) if (u != fa) {
                dfs(u, now, d + 1);
                sz[now] += sz[u];
                if (maxson[now] == -1 || sz[u] > sz[maxson[now]]) maxson[now] = u;
            }
        }
        void link(int now, int t) {
            top[now] = t;
            if (maxson[now] == -1) return;
            link(maxson[now], t);
            for (int u : G[now]) if (u != p[now]) {
                if (u == maxson[now]) continue;
                link(u, u);
            }
        }
        
    public:
        HeavyLightDecomp(int n): n(n) {
            clk = 0;
            memset(tin, 0, sizeof(tin)); memset(top, 0, sizeof(top)); memset(dep, 0, sizeof(dep));
            memset(maxson, 0, sizeof(maxson)); memset(sz, 0, sizeof(sz)); memset(p, 0, sizeof(p));
            memset(rev, 0, sizeof(rev));
        }
        void add_edge(int a, int b) {
            G[a].push_back(b);
            G[b].push_back(a);
        }
        void solve() {
            dfs(0, -1, 0);
            for (int i = 0; i < n; ++i) rev[tin[i]] = i;
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
        inline int timein(int vtx) { return tin[vtx]; }
        inline int id(int t) { return rev[t]; }
};
