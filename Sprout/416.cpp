#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5, mod = 1e9 + 7;
int dp[maxn][maxn], s[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, a, b, k; cin >> n >> a >> b >> k;
    dp[0][a] = 1;
    for (int i = a; i <= n; ++i) s[i] = 1;
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j == b) continue;
            if (j < b) {
                int l = 1, r = (b + j) % 2 == 0 ? (b + j) / 2 - 1 : (b + j) / 2;
                dp[i][j] = (s[r] - s[l - 1]) % mod;
                if (j >= l && j <= r) dp[i][j] = (dp[i][j] - dp[i - 1][j]) % mod;
                while (dp[i][j] < 0) dp[i][j] += mod;
            } else {
                int r = n, l = (b + j) / 2 + 1;
                dp[i][j] = (s[r] - s[l - 1]) % mod;
                if (j >= l && j <= r) dp[i][j] = (dp[i][j] - dp[i - 1][j]) % mod;
                while (dp[i][j] < 0) dp[i][j] += mod;
            }
        }
        memset(s, 0, sizeof(s));
        for (int j = 1; j <= n; ++j) s[j] = (s[j - 1] + dp[i][j]) % mod;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = (ans + dp[k][i]) % mod;
    cout << ans << endl;
    return 0;
}
