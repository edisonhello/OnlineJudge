struct SCC {
    vector<int> G[maxn], R[maxn], topo;
    int n, nscc;
    vector<int> scc, sz;
    bitset<maxn> v;
    void dfs(int now) {
        v[now] = true;
        for (int u : G[now]) if (!v[u]) {
            dfs(u);
        }
        topo.push_back(now);
    }
    void rdfs(int now) {
        v[now] = true;
        scc[now] = nscc;
        ++sz[nscc];
        for (int u : R[now]) if (!v[u]) {
            rdfs(u);
        }
    }
    SCC(): {}
    SCC(int n): n(n) {
        scc.assign(n, 0); sz.assign(n, 0);
    }
    void add_edge(int a, int b) {
        G[a].push_back(b);
        R[b].push_back(a);
    }
    void solve() {
        v.reset();
        for (int i = 0; i < n; ++i) if (!v[i]) dfs(i);
        reverse(topo.begin(), topo.end());
        v.reset();
        for (int i : topo) if (!v[i]) {
            ++nscc;
            rdfs(i);
        } 
    }
};
