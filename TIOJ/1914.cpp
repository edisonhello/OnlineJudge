#include <bits/stdc++.h>
using namespace std;

const int maxn = 200 + 10, inf = 1e4;
int dp[maxn][maxn][maxn], c[maxn];

int go(int l, int r, int b) {
    if (l > r) return 0;
    if (l == r) {
        if (c[l] == b) return 0;
        return 1;
    }
    if (dp[l][r][b]) return dp[l][r][b];
    dp[l][r][b] = 0;
    for (int i = l; i <= r; ++i) {
        if (c[i] != b) {
            dp[l][r][b] = 1 + go(i + 1, r, b);
            for (int j = i + 1; j <= r; ++j) if (c[i] == c[j]) {
                dp[l][r][b] = min(dp[l][r][b], 1 + go(i + 1, j, c[i]) + go(j + 1, r, b));
            }
            return dp[l][r][b];
        }
    }
    return dp[l][r][b];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, m; cin >> n >> m;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) cin >> c[i];
        cout << go(1, n, 0) << endl;
    }
    return 0;
}
