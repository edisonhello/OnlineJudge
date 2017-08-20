#include <bits/stdc++.h>
using namespace std;

const int maxn = 200 + 10, inf = 1e9 + 1;

template <typename T> class Dinic {
    private:
        int level[maxn], n, s, t;
        struct Edge {
            int to, rev;
            T cap;
            Edge() {}
            Edge(int a, T b, int c): to(a), cap(b), rev(c) {}
        };
        vector<Edge> G[maxn];
        bool bfs() {
            memset(level, -1, sizeof(level));
            level[s] = 0; 
            queue<int> que; que.push(s);
            while (que.size()) {
                int tmp = que.front(); que.pop();
                for (auto e : G[tmp]) {
                    if (e.cap > 0 && level[e.to] == -1) {
                        level[e.to] = level[tmp] + 1;
                        que.push(e.to);
                    }
                }
            }
            return level[t] != -1;
        }
        T flow(int now, T low) {
            if (now == t) return low;
            T ret = 0;
            for (auto &e : G[now]) {
                if (e.cap > 0 && level[e.to] == level[now] + 1) {
                    T tmp = flow(e.to, min(e.cap, low - ret));
                    e.cap -= tmp; G[e.to][e.rev].cap += tmp;
                    ret += tmp;
                }
            }
            if (ret == 0) level[now] = -1;
            return ret;
        }
    public:
        Dinic(int _n, int _s, int _t): n(_n), s(_s), t(_t) {
            fill(G, G + maxn, vector<Edge>());
        }
        void add_edge(int a, int b, T c) {
            G[a].push_back(Edge(b, c, G[b].size()));
            G[b].push_back(Edge(a, 0, G[a].size() - 1));
        }
        T maxflow() {
            T ret = 0;
            while (bfs()) ret += flow(s, inf);
            return ret;
        }
};

int a[maxn], b[maxn], n;

bool check(int tm) {
    cout << "check tm = " << tm << endl;
    int s = n * 2 + 1, t = n * 2 + 2;
    Dinic<int> flow(n * 2 + 2, s, t);
    for (int i = 1; i <= n; ++i) flow.add_edge(s, i, tm);
    for (int i = 1; i <= n; ++i) flow.add_edge(i + n, t, tm);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (min(b[i], b[j]) - max(a[i], a[j]) > 0) flow.add_edge(j, i + n, min(b[i], b[j]) - max(a[i], a[j]));
        }
    }
    return flow.maxflow() == tm * n;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
    int d = 1, ans = 0; while (d <= (int)1e5) d <<= 1;
    while (d >>= 1) if (ans + d <= (int)1e5) if (check(ans + d)) ans += d;
    cout << ans * n << endl;
    return 0;
}
