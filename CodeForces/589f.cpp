#include <bits/stdc++.h>
// #define getchar gtx
using namespace std;

const int maxn = 10000 + 100 + 10, inf = 1e9 + 1;
int a[maxn], b[maxn], n, mx;

inline int gtx() {
    const int N = 1048576;
    static char buffer[N];
    static char *p = buffer, *end = buffer;
    if (p == end) {
        if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
        p = buffer;
    }
    return *p++;
}

template <typename T>
inline bool rit(T& x) {
    char __c = 0; bool flag = false;
    while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
    __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
    while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
    if (flag) x = -x;
    return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

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

bool check(int tm) {
    // cout << "check tm = " << tm << endl;
    int s = 0, t = maxn - 1;
    Dinic flow(maxn, s, t);
    for (int i = 1; i <= n; ++i) {
        for (int j = a[i]; j <= b[i]; ++j) flow.add_edge(i, j + n, 1);
    }
    for (int i = 1; i <= mx; ++i) flow.add_edge(i + n, t, 1);
    for (int i = 1; i <= n; ++i) flow.add_edge(s, i, tm);
    return flow.maxflow() == n * tm;
}

int main() {
    rit(n);
    int ub = 0;
    for (int i = 1; i <= n; ++i) rit(a[i], b[i]), ++a[i], ub = max(b[i] - a[i] + 1, ub), mx = max(mx, b[i]);
    // cout << "mx = " << mx << endl;
    int d = 1, ans = 0; while (d <= ub) d <<= 1;
    while (d >>= 1) if (ans + d <= ub) if (check(ans + d)) ans += d;
    printf("%d\n", ans * n);
}
