int dp[maxk][maxn], f[maxk][maxn];

void go(int k, int l, int r, int fl, int fr) {
    if (l > r) return;
    int m = (l + r) >> 1;
    f[k][m] = -1;
    for (int i = fl; i <= min(m - 1, fr); ++i) {
        int t = dp[k - 1][i] + f(i + 1, m);
        if (t > dp[k][m]) {
            dp[k][m] = t;
            f[k][m] = i;
        }
    }
    go(k, l, m - 1, fl, f[k][m]);
    go(k, m + 1, r, f[k][m], fr);
}

void solve() {
    for (int i = 1; i <= k; ++i) go(i, 1, n, 0, n - 1);
}
