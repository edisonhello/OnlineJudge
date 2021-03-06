#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e3 + 10, inf = 1e9 + 1;

struct MincostMaxflow {
    struct Edge {
        int to, rev, cap, w;
        Edge() {}
        Edge(int a, int b, int c, int d): to(a), cap(b), w(c), rev(d) {}
    };
    int n, s, t, p[maxn], id[maxn];
    int d[maxn];
    bool inque[maxn];
    vector<Edge> G[maxn];
    pair<int, int> spfa() {
        memset(p, -1, sizeof(-1));
        fill(d, d + maxn, inf);
        memset(id, -1, sizeof(id));
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
    MincostMaxflow(int _n, int _s, int _t): n(_n), s(_s), t(_t) {
        fill(G, G + maxn, vector<Edge>());
    }
    void add_edge(int a, int b, int cap, int w) {
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
        return make_pair(mxf, mnc);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; while (cin >> n >> m) {
        MincostMaxflow flow(n * 2, 1, 2 * n);
        for (int i = 2; i < n; ++i) flow.add_edge(i, i + n, 1, 0);
        flow.add_edge(1, n + 1, 2, 0);
        flow.add_edge(n, n + n, 2, 0);
        while (m--) {
            int a, b, c; cin >> a >> b >> c;
            flow.add_edge(a + n, b, 1, c);
        }
        auto ans = flow.maxflow();
        cout << ans.second << endl;
    }
    return 0;
}
