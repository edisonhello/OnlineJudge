#include <bits/stdc++.h>
using namespace std;

const int maxn = 300 + 10;
const long long inf = 1e18;
long long dp[maxn][maxn];
pair<pair<int, int>, int> p[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) cin >> p[i].first.first >> p[i].first.second >> p[i].second;
    sort(p, p + m, [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        return a.first.second < b.first.second;
    });
    for (int i = 0; i < maxn; ++i) for (int j = 0; j < maxn; ++j) dp[i][j] = inf;
    for (int i = 0; i < maxn; ++i) dp[0][i] = 0;
    for (int i = 1; i <= n; ++i) {
        int ind = 0;
        long long mn = inf;
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = mn;
            while (ind < m && p[ind].first.second <= j) {
                int fixed = p[ind].first.second - p[ind].first.first + 1;
                if (i - fixed >= 0) dp[i][j] = min(dp[i][j], dp[i - fixed][p[ind].first.first - 1] + p[ind].second);
                ++ind;
            }
            mn = min(mn, dp[i][j]);
        }
    }
    long long ans = inf;
    for (int i = k; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) ans = min(ans, dp[i][j]);
    }
    cout << (ans == inf ? -1 : ans) << endl;
    return 0;
}
