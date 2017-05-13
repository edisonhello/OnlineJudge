#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, lg = 20;
vector<pair<int, int>> G[maxn];
struct Edge { int from, to, w; };
vector<Edge> edge;
int fa[lg][maxn], dis[lg][maxn], dep[maxn];
bool v[maxn];

struct Djs {
    int _djs[maxn];
    void init() {
        for (int i = 0; i < maxn; ++i) _djs[i] = i;
    }
    int F(int x) { return _djs[x] == x ? x : _djs[x] = F(_djs[x]); }
    void U(int x, int y) {
        x = F(x), y = F(y);
        _djs[x] = y;
    }
} djs;

inline void init();
inline void kruskal();
void dfs(int, int, int, int);
int lca(int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        init();
        int n, m, q; cin >> n >> m >> q;
        while (m--) {
            int a, b, k; cin >> a >> b >> k;
            edge.push_back((Edge){ a, b, k });
        }
        kruskal();
        for (int i = 0; i < n; ++i) if (!v[i]) dfs(i, -1, 0, 0);
        while (q--) {
            int tp; cin >> tp;
            if (tp == 0) {
                int a, b, k; cin >> a >> b >> k;
            } else {
                int a, b; cin >> a >> b;
                cout << lca(a, b) << '\n';
            }
        }
    }
    return 0;
}
inline void init() {
    fill(G, G + maxn, vector<pair<int, int>>());
    edge.clear();
    djs.init();
    memset(v, false, sizeof(v));
    memset(dep, 0, sizeof(dep));
}
inline void kruskal() {
    sort(edge.begin(), edge.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });
    for (Edge e : edge) {
        int x = djs.F(e.from), y = djs.F(e.to);
        if (x == y) continue;
        G[x].push_back(make_pair(y, e.w));
        G[y].push_back(make_pair(x, e.w));
        djs.U(e.from, e.to);
    }
}
void dfs(int x, int f, int d, int w) {
    fa[0][x] = f;
    dep[x] = d;
    dis[0][x] = w;
    for (int i = 1; i < lg; ++i) {
        if ((1 << i) > d) break;
        fa[i][x] = fa[i - 1][fa[i - 1][x]];
        dis[i][x] = max(dis[i - 1][x], dis[i - 1][fa[i - 1][x]]);
    }
    for (auto p : G[x]) if (p.first != f) {
        dfs(p.first, x, d + 1, p.second);
    }
}
int lca(int a, int b) {
    if (a == b) return 0;
    if (dep[a] > dep[b]) swap(a, b);
    int ret = -(int)1e8 + 1;
    for (int i = 0; i < lg; ++i) if ((dep[b] - dep[a]) >> i & 1) {
        ret = max(ret, dis[i][b]);
        b = fa[i][b];
    }
    if (a == b) return ret;
    for (int i = lg - 1; i >= 0; --i) if (fa[i][a] != fa[i][b]) {
        ret = max({ ret, dis[i][a], dis[i][b] });
        a = fa[i][a]; b = fa[i][b];
    }
    if (a == b) return ret;
    return max({ ret, dis[0][a], dis[0][b] });
}
