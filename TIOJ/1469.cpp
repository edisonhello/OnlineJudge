#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10, inf = 1e9 + 1;
map<string, int> mp = { {"XS", 1}, {"S", 2}, {"M", 3}, {"L", 4}, {"XL", 5}, {"XXL", 6} };

struct Dinic {
    int n, s, t;
    vector<int> level;
    struct Edge {
        int to, rev, cap;
        Edge() {}
        Edge(int a, int b, int c): to(a), cap(b), rev(c) {}
    };
    vector<Edge> G[maxn];
    bool bfs() {
        level.assign(n, -1);
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
    int flow(int now, int low) {
        if (now == t) return low;
        int ret = 0;
        for (auto &e : G[now]) {
            if (e.cap > 0 && level[e.to] == level[now] + 1) {
                int tmp = flow(e.to, min(e.cap, low - ret));
                e.cap -= tmp; G[e.to][e.rev].cap += tmp;
                ret += tmp;
            }
        }
        if (ret == 0) level[now] = -1;
        return ret;
    }
    Dinic(int _n, int _s, int _t): n(_n), s(_s), t(_t) {
        fill(G, G + maxn, vector<Edge>());
    }
    void add_edge(int a, int b, int c) {
        G[a].push_back(Edge(b, c, G[b].size()));
        G[b].push_back(Edge(a, 0, G[a].size() - 1));
    }
    int maxflow() {
        int ret = 0;
        while (bfs()) ret += flow(s, inf);
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; while (cin >> n >> m) {
        int s = 0, t = m + 6 + 1;
        Dinic flow(m + 6 + 2, s, t);
        for (int i = 1; i <= 6; ++i) {
            flow.add_edge(s, i, n / 6);
        }
        for (int i = 1; i <= m; ++i) {
            string a, b; cin >> a >> b;
            flow.add_edge(mp[a], i + 6, 1);
            flow.add_edge(mp[b], i + 6, 1);
        }       
        for (int i = 1; i <= m; ++i) {
            flow.add_edge(i + 6, t, 1);
        }
        cout << (flow.maxflow() == m ? "YES" : "NO") << endl;
    }
    return 0;
}
