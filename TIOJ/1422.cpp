#include <bits/stdc++.h>
using namespace std;

const int maxn = 300 + 10, inf = 1e9 + 1;

struct MCMF {
    struct Edge {
        int to, rev, cap, w;
        Edge() {}
        Edge(int a, int b, int c, int d): to(a), cap(b), w(c), rev(d) {}
    };
    int n, s, t;
    vector<int> p, id, d;
    bitset<maxn> inque;
    vector<Edge> G[maxn];
    pair<int, int> spfa() {
        p.assign(n, -1);
        d.assign(n, inf);
        id.assign(n, -1);
        d[s] = 0; p[s] = s;
        queue<int> que; que.push(s); inque[s] = true;
        while (que.size()) {
            int tmp = que.front(); que.pop();
            inque[tmp] = false;
            int i = 0;
            for (auto e : G[tmp]) {
                if (e.cap > 0 && d[e.to] > d[tmp] + e.w) {
                    d[e.to] = d[tmp] + e.w;
                    p[e.to] = tmp;
                    id[e.to] = i;
                    if (!inque[e.to]) que.push(e.to), inque[e.to] = true;
                }
                ++i;
            }
        }
        if (d[t] == inf) return make_pair(-1, -1);
        int a = inf;
        for (int i = t; i != s; i = p[i]) {
            a = min(a, G[p[i]][id[i]].cap);
        }
        for (int i = t; i != s; i = p[i]) {
            Edge &e = G[p[i]][id[i]];
            e.cap -= a; G[e.to][e.rev].cap += a;
        }
        return make_pair(a, d[t]);
    }
    MCMF(int _n, int _s, int _t): n(_n), s(_s), t(_t) {
        fill(G, G + maxn, vector<Edge>());
    }
    void add_edge(int a, int b, int cap, int w) {
        cout << a << ' ' << b << ' ' << cap << endl;
        // cout << a << " -> " << b << " cap = " << cap << " w = " << w << endl;
        G[a].push_back(Edge(b, cap, w, (int)G[b].size()));
        G[b].push_back(Edge(a, 0, -w, (int)G[a].size() - 1));
    }
    pair<int, int> maxflow() {
        int mxf = 0, mnc = 0;
        while (true) {
            pair<int, int> res = spfa();
            if (res.first == -1) break;
            mxf += res.first; mnc += res.first * res.second;
        }
        // cout << "mxf = " << mxf << " mnc = " << mnc << endl;
        return make_pair(mxf, mnc);
    }
};

int main() {
    int n, m; cin >> n >> m;
    if (n < m) swap(n, m);
    int s = 0, t = n * m * 2 + 1;
    cout << "s = " << s << " t = " << t << endl;
    MCMF flow(n * m * 2 + 2, s, t);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int now = (i - 1) * m + j;
            // cout << "now = " << now << endl;
            flow.add_edge(s, now, inf, 1); flow.add_edge(now, now + n * m, inf, 0);
            for (int k = 1; k <= n; ++k) if (k != i) flow.add_edge(now, (k - 1) * m + j + n * m, inf, 0);
            for (int k = 1; k <= m; ++k) if (k != j) flow.add_edge(now, (i - 1) * m + k + n * m, inf, 0);
            for (int k = -n; k <= n; ++k) if (k != 0) {
                if (i + k <= n && i + k >= 1 && j + k <= m && j + k >= 1) flow.add_edge(now, (i + k - 1) * m + (j + k) + n * m, inf, 0);
            }
            for (int k = -n; k <= n; ++k) if (k != 0) {
                if (i - k <= n && i - k >= 1 && j + k <= m && j + k >= 1) flow.add_edge(now, (i - k - 1) * m + (j + k) + n * m, inf, 0);
            }
            flow.add_edge(now + n * m, t, 1, 0);
        }
    }
    auto f = flow.maxflow();
    cout << f.first << ' ' << f.second << endl;
    return 0;
}
