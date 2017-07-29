#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
vector<int> G[maxn], R[maxn], SCC[maxn];
bool v[maxn];
stack<int> topo;
int cnt, scc[maxn], sz[maxn], mem[maxn];

void dfs(int);
void rdfs(int);
int dp(int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); R[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) if (!v[i]) dfs(i);
    memset(v, false, sizeof(v));
    while (true) {
        while (topo.size() && v[topo.top()]) topo.pop();
        if (!topo.size()) break;
        ++cnt, rdfs(topo.top()); topo.pop();
    }
    for (int i = 0; i < n; ++i) {
        for (int u : G[i]) SCC[scc[u]].push_back(scc[i]);
    }
    int ans = 0;
    for (int i = 1; i <= cnt; ++i) ans = max(ans, dp(i));
    cout << ans << endl;
    return 0;
}

void dfs(int x) {
    v[x] = true;
    for (int u : G[x]) if (!v[u]) dfs(u);
    topo.push(x);
}

void rdfs(int x) {
    v[x] = true; scc[x] = cnt; ++sz[cnt];
    for (int u : R[x]) if (!v[u]) rdfs(u);
}

int dp(int x) {
    if (mem[x]) return mem[x];
    mem[x] = sz[x];
    if (SCC[x].size() == 0) return mem[x];
    for (int u : SCC[x]) if (u != x) mem[x] = max(mem[x], dp(u) + sz[x]);
    return mem[x];
}
