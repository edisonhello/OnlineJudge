template <typename T> class Dinic {
    private:
        int n, s, t, cnt, level[maxn];
        T w[maxn][maxn];
        bool bfs() {
            memset(level, -1, sizeof(level));
            queue<int> que; que.push(s);
            level[s] = 0;
            while (que.size()) {
                int tmp = que.front(); que.pop();
                for (int i = 0; i < n; ++i) if (w[tmp][i] > 0) {
                    if (level[i] == -1) {
                        level[i] = level[tmp] + 1;
                        que.push(i);
                    }
                }
            }
            return level[t] != -1;
        }
        T flow(int now, T low) {
            T res = 0;
            if (now == t) return low;
            for (int i = 0; i < n && res < low; ++i) if (w[now][i] > 0) {
                if (level[i] == level[now] + 1) {
                    T tmp = flow(i, min(w[now][i], low - res));
                    w[now][i] -= tmp; w[i][now] += tmp;
                    res += tmp;
                }
            }
            if (!res) level[now] = -1;
            return res;
        }
    public:
        Dinic(int _n, int _s, int _t): n(_n), s(_s), t(_t) {
            memset(w, 0, sizeof(w));
        }
        void add_edge(int a, int b, T flow) {
            w[a][b] = flow;
        }
        T maxflow() {
            long long ans = 0;
            while (bfs()) ans += flow(s, inf);
            return ans;
        }
        vector<vector<T>> get_w() {
            vector<vector<T>> ret;
            for (int i = 0; i < n; ++i) {
                ret.push_back(vector<T>());
                for (int j = 0; j < n; ++j) ret[i].push_back(w[i][j]);
            }
            return ret;
        }
};

