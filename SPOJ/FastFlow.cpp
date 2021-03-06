#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 10, maxe = 60000 + 10;
const long long inf = 1e18 + 1;

template <typename T> class Dinic {
    private:
        int level[maxn], head[maxn], next[maxe], to[maxe], n, s, t, cnt;
        T w[maxe];
        bool bfs() {
            memset(level, -1, sizeof(level));
            level[s] = 0; 
            queue<int> que; que.push(s);
            while (que.size()) {
                int tmp = que.front(); que.pop();
                for (int i = head[tmp]; ~i; i = next[i]) {
                    if (w[i] > 0 && level[to[i]] == -1) {
                        level[to[i]] = level[tmp] + 1;
                        que.push(to[i]);
                    }
                }
            }
            return level[t] != -1;
        }
        T flow(int now, T low) {
            if (now == t) return low;
            long long ret = 0;
            for (int i = head[now]; ~i; i = next[i]) {
                if (w[i] > 0 && level[to[i]] == level[now] + 1) {
                    long long tmp = flow(to[i], min(w[i], low - ret));
                    w[i] -= tmp; w[i ^ 1] += tmp;
                    ret += tmp;
                }
            }
            if (ret == 0) level[now] = -1;
            return ret;
        }
    public:
        Dinic(int _n, int _s, int _t): n(_n), s(_s), t(_t) {
            memset(head, -1, sizeof(head));
        }
        void add_edge(int a, int b, T c) {
            to[cnt] = b; next[cnt] = head[a]; w[cnt] = c; head[a] = cnt++;
        }
        T maxflow() {
            T ret = 0;
            while (bfs()) ret += flow(s, inf);
            return ret;
        }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    Dinic<long long> dinic(n, 1, n);
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        dinic.add_edge(a, b, c); dinic.add_edge(b, a, c);
    }
    cout << dinic.maxflow() << endl;
    return 0;
}
