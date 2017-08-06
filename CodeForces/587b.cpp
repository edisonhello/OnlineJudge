#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10, mod = 1e9 + 7;
int a[maxn], sum[2][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; long long l; cin >> n >> l >> k;
    vector<int> v;
    for (int i = 0; i < n; ++i) cin >> a[i], v.push_back(a[i]);
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 0; i < n; ++i) a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    vector<vector<int>> dp = vector<vector<int>>(k + 1);
    for (int i = 0; i < dp.size(); ++i) dp[i] = vector<int>(n + 1, 0);
    int cur = 0;
    for (int j = 0; j < n; ++j) dp[1][j] = 1;
    for (int i = 2; i <= k; ++i) {
        memset(sum[cur], 0, sizeof(sum[cur]));
        for (int j = 0; j < n; ++j) {
            dp[i][j] = (sum[cur ^ 1][a[i]] + 1) % mod;
            sum[cur][a[i]] = (sum[cur][a[i]] + dp[i][j]) % mod;
        }
        cur ^= 1;
    }
    int ans = 0;
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < n; ++j) ans = (ans + dp[i][j]) % mod;
    }
    cout << ans << endl;
    return 0;
}
