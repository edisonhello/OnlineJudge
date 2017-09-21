#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10, inf = 1e9;
long long dp[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, c, u, x, y; cin >> n >> c >> x >> u >> y;
    dp[0][0] = c;
    for (int i = 1; i <= n; ++i) dp[0][i] = -inf;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j && dp[i - 1][j - 1] >= u) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] - u);
            dp[i][j] += x + j * y;
            // cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
        }
    }
    long long ans = 0;
    for (int i = 0; i <= n; ++i) ans = max(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}
