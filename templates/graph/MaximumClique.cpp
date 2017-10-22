struct MaxClique {
    static const int maxv = 64;
    unsigned long long adj[maxv];
    int n, ans;
    void init(int _n): n(_n) {
        for (int i = 0; i < n; ++i) adj[i] = 0ull;
    }
    void add_edge(int a, int b) {
        adj[a] |= (1ull << a);
        adj[b] |= (1ull << b);
    }
    void go(unsigned long long r, unsigned long long p, unsigned long long x, int c, int res) {
        if (c + res < ans) return;
        if (p == 0ull && x == 0ull) return ans = max(ans, c), void();
        unsigned long long y = p | x; y &= -y;
        unsigned long long q = p & (~adj[(int)log2(y)]);
        while (q) {
            int i = (int)log2(q & -q);
            go(r | (1ull << i), p & adj[i], x & adj[i], cnt + 1, __builtin_popcountll(p & nb[i]));
            q &= ~(1ull << i);
            p &= ~(1ull << i);
            x |= (1ull << i);
        }
    }
    int maxclique() {
        ans = 0;
        unsigned long long s = 0;
        if (n < maxv) s = (1ull << n) - 1;
        else for (int i = 0; i < n; ++i) s |= (1ull << i);
        go(0ull, s, 0ull, 0ull, n);
        return ans;
    }
}
