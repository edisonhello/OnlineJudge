#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 30, inf = 1e9 + 1;
vector<int> w[maxn];
int cnt[10], ans[maxn];

int get(const string& s) {
    if (s == "S") return 1;
    if (s == "M") return 2;
    if (s == "L") return 3;
    if (s == "XL") return 4;
    if (s == "XXL") return 5;
    if (s == "XXXL") return 6;
}

string rev(int i) {
    if (i == 1) return "S";
    if (i == 2) return "M";
    if (i == 3) return "L";
    if (i == 4) return "XL";
    if (i == 5) return "XXL";
    if (i == 6) return "XXXL";
}

struct Dinic {
    int level[maxn], n, s, t;
    struct Edge {
        int to, rev, cap;
        Edge() {}
        Edge(int a, int b, int c): to(a), cap(b), rev(c) {}
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
    for (int i = 1; i <= 6; ++i) cin >> cnt[i];
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s; cin >> s;
        int pos = -1;
        for (int j = 0; j < s.length(); ++j) {
            if (s[j] == ',') { pos = j; break; }
        }
        if (pos == -1) w[i].push_back(get(s));
        else w[i].push_back(get(s.substr(0, pos))), w[i].push_back(get(s.substr(pos + 1, s.length() - pos - 1)));
    }
    int o = 0;
    for (int i = 1; i <= n; ++i) {
        if (w[i].size() == 1) {
            ++o;
            if (cnt[w[i][0]]) ans[i] = w[i][0], --cnt[w[i][0]];
            else return cout << "NO" << endl, 0;
        }
    }
    int s = 1, t = 2 * n + 20;
    Dinic flow(2 * n + 20, s, t);
    for (int i = 1; i <= n; ++i) if (w[i].size() == 2) {
        flow.add_edge(s, i, inf);
        flow.add_edge(i, i + n, 1);
        flow.add_edge(i + n, n * 2 + w[i][0], 1);
        flow.add_edge(i + n, n * 2 + w[i][1], 1);
    }
    for (int i = 1; i <= 6; ++i) {
        flow.add_edge(n * 2 + i, n * 2 + i + 6, cnt[i]);
        flow.add_edge(n * 2 + i + 6, t, inf);
    }
    int mf = flow.maxflow();
    if (mf != n - o) return cout << "NO" << endl, 0;
    for (int i = 1; i <= n; ++i) if (w[i].size() == 2) {
        for (auto j : flow.G[i + n]) {
            if (j.to == n * 2 + w[i][0] && j.cap == 0) ans[i] = w[i][0];
            else if (j.to == n * 2 + w[i][1] && j.cap == 0) ans[i] = w[i][1];
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) cout << rev(ans[i]) << endl;
    return 0;
}
