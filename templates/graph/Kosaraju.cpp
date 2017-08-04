class SCC {
    private:
        vector<int> G[maxn], R[maxn], topo;
        int n, nscc, scc[maxn], sz[maxn];
        bool v[maxn];
        void dfs(int now) {
            v[now] = true;
            scc[now] = nscc;
            ++sz[nscc];
            for (int u : G[now]) if (!v[u]) {
                dfs(u);
            }
        }
        void rdfs(int now) {
            v[now] = true;
            for (int u : R[now]) if (!v[u]) {
                rdfs(u);
            }
            topo.push_back(now);
        }
    public:
        SCC(int n): n(n) {}
        void add_edge(int a, int b) {
            G[a].push_back(b);
            R[b].push_back(a);
        }
        void solve() {
            memset(v, false, sizeof(v));
            for (int i = 0; i < n; ++i) if (!v[i]) rdfs(i);
            reverse(topo.begin(), topo.end());
            memset(v, false, sizeof(v));
            for (int i : topo) if (!v[i]) {
                ++nscc;
                dfs(i);
            } 
        }
        inline int nscc() { return nscc; }
        inline int id(int vtx) { return scc[vtx]; }
        inline maxsxx() { return *max_element(sz, sz + maxn); }
};
