#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 200 + 10, inf = 1e9 + 1;
int w[maxn][maxn], dp[2][maxn][maxn];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m; cin >> m;
    for (int i = 1; i <= m; ++i) for (int j = 1; j <= m; ++j) cin >> w[i][j];
    vector<int> vec; int t;
    vec.push_back(0);
    while (cin >> t) vec.push_back(t);
    for (int i = 0; i < maxn; ++i) for (int j = 0; j < maxn; ++j) dp[0][i][j] = dp[1][i][j] = inf;
    dp[0][1][2] = w[3][vec[1]]; dp[0][2][3] = w[1][vec[1]]; dp[0][1][3] = w[2][vec[1]];
    int cur = 1;
    for (int i = 2; i < vec.size(); ++i) {
        int a = vec[i], b = vec[i - 1];
        for (int j = 1; j <= m; ++j) {
            for (int k = j + 1; k <= m; ++k) {
                dp[cur][j][k] = min(dp[cur][j][k], dp[cur ^ 1][j][k] + w[b][a]);
                dp[cur][min(b, j)][max(b, j)] = min(dp[cur][min(b, j)][max(b, j)], dp[cur ^ 1][j][k] + w[k][a]);
                dp[cur][min(b, k)][max(b, k)] = min(dp[cur][min(b, k)][max(b, k)], dp[cur ^ 1][j][k] + w[j][a]);
            }
        }
        for (int j = 0; j < maxn; ++j) for (int k = 0; k < maxn; ++k) dp[cur ^ 1][j][k] = inf;
        cur ^= 1;
    }
    int ans = inf;
    for (int i = 1; i <= m; ++i) {
        for (int j = i; j <= m; ++j) ans = min(ans, dp[cur ^ 1][i][j]);
    }
    cout << ans << endl;
    return 0;
}
