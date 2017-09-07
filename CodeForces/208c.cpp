#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
int w[maxn][maxn];
pair<int, int> dp[maxn][maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    for (int i = 0; i < maxn; ++i) for (int j = 0; j < maxn; ++j) w[i][j] = maxn;
    for (int i = 0; i < maxn; ++i) w[i][i] = 0;
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        w[a][b] = w[b][a] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                dp[i][j][k].first = w[j][k];
                if (dp[i][j][k].first == maxn) continue;
                if (j == i || k == i) dp[i][j][k].second = 1;
            }
        }
    }
    for (int c = 1; c <= n; ++c) {
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (dp[c][i][k].first + dp[c][k][j].first < dp[c][i][j].first) {
                        dp[c][i][j] = make_pair(dp[c][i][k].first + dp[c][k][j].first, dp[c][i][k].second + dp[c][k][j].second);
                    } else if (dp[c][i][k].first + dp[c][k][j].first == dp[c][i][j].first) {
                        if (dp[c][i][k].second + dp[c][k][j].second > dp[c][i][j].second) dp[c][i][j].second = dp[c][i][k].second + dp[c][k][j].second;
                    }
                }
            }
        }
    }
    double ans = 0.0;
    for (int c = 1; c <= n; ++c) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) cnt += dp[c][1][i].second;
        ans = max(ans, (double)cnt / (double)n);
    }
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}
