template <typename T> class Hungarian {
    private:
        T w[maxn][maxn], lx[maxn], ly[maxn], inf;
        int match[maxn], n;
        bool s[maxn], t[maxn];
        bool dfs(int now) {
            s[now] = true;
            for (int i = 0; i < n; ++i) {
                if (lx[now] + ly[i] == w[now][i] && !t[i]) {
                    t[i] = true;
                    if (match[i] == -1 || dfs(match[i])) {
                        match[i] = now;
                        return true;
                    }
                }
            }
            return false;
        }
        void relabel() {
            T a = inf;
            for (int i = 0; i < n; ++i) if (s[i]) {
                for (int j = 0; j < n; ++j) if (!t[j]) {
                    a = min(a, lx[i] + ly[j] - w[i][j]);
                }
            }
            for (int i = 0; i < n; ++i) {
                if (s[i]) lx[i] -= a;
                if (t[i]) ly[i] += a;
            }
        }
    public:
        Hungarian(int n, T inf=1e9 + 1): n(n), inf(inf) {
            memset(w, 0, sizeof(w));
            memset(lx, 0, sizeof(lx));
            memset(ly, 0, sizeof(ly));
            memset(match, -1, sizeof(match));
        }
        void add_edge(int a, int b, T c) {
            w[a][b] = c;
        }
        T solve() {
            for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) lx[i] = max(lx[i], w[i][j]);
            for (int i = 0; i < n; ++i) {
                while (true) {
                    memset(s, false, sizeof(s)); memset(t, false, sizeof(t));
                    if (dfs(i)) break;
                    else relabel();
                }
            }
            T ans = 0;
            for (int i = 0; i < n; ++i) ans += w[match[i]][i];
            return ans;
        }
};
