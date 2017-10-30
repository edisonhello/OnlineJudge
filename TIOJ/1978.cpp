#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 80;
const double time_limit = 0.040;
bitset<maxn> adj[maxn], v;
vector<int> vertex, G[maxn];
int ans, n, m, c[maxn], mx[maxn], deg[maxn];

void go(bitset<maxn> r, bitset<maxn> p) {
    if (1.0 * clock() / CLOCKS_PER_SEC >= time_limit) return;
    if (p.count() == 0) return ans = max(ans, (int)r.count()), void();
    if ((r | p).count() <= ans) return;
    int now = p._Find_first();
    bitset<maxn> cur = p & ~adj[now];
    for (now = cur._Find_first(); now < n; now = cur._Find_next(now)) {
        r[now] = true;
        go(r, p & adj[now]);
        r[now] = false;
        p[now] = false;
    }
}

bool dfs1(int now, int cur) {
    c[now] = cur; v[now] = true;
    bool ret = true;
    for (int u : G[now]) {
        if (v[u] && c[u] == cur) ret = false;
        else if (v[u] && c[u] == cur ^ 1) continue;
        if (!v[u]) ret &= dfs1(u, cur ^ 1);
    }
    return ret;
}

bool dfs2(int now) {
    v[now] = true;
    for (int u : G[now]) {
        if (mx[u] == -1 || !v[mx[u]] && dfs2(mx[u])) {
            mx[u] = now;
            return true;
        }
    }
    return false;
}

int main() {
    clock();
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) vertex.push_back(i);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) adj[i][j] = true;
        adj[i][i] = false;
    }
    vector<pair<int, int>> edge;
    fill(c, c + n, -1);
    while (m--) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
        ++deg[a]; ++deg[b];
        edge.emplace_back(a, b);
    }
    bool bipartite = true;
    for (int i = 0; i < n; ++i) if (!v[i]) bipartite &= dfs1(i, 0);
    if (bipartite) {
        fill(mx, mx + n, -1);
        int match = 0;
        for (int i = 0; i < n; ++i) {
            v.reset();
            if (dfs2(i)) ++match;
        }
        cout << n - match / 2 << endl;
        return 0;
    }
    bitset<maxn> r, p;
    sort(vertex.begin(), vertex.end(), [&](const int &a, const int &b) { return deg[a] < deg[b]; });
    vector<int> id(n);
    for (int i = 0; i < n; ++i) id[vertex[i]] = i;
    for (pair<int, int> &e : edge) {
        adj[id[e.first]][id[e.second]] = false;
        adj[id[e.second]][id[e.first]] = false;
    }
    for (int i = 0; i < n; ++i) p[i] = true;
    go(r, p);
    cout << ans << endl;
    return 0;
}
