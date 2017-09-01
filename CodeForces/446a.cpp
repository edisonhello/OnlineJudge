#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int dp[2][maxn], a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        if (a[i] > a[i - 1]) {
            dp[0][i] = dp[0][i - 1] + 1;
            if (i > 2 && a[i - 1] <= a[i - 2] && a[i] == a[i - 2] + 1) dp[1][i] = 1;
            else dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]) + 1;
        } else {
            dp[0][i] = 1;
            if (i > 2 && a[i - 1] <= a[i - 2] && a[i] == a[i - 2] + 1) dp[1][i] = 1;
            else dp[1][i] = dp[0][i - 1] + 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) cout << "i = " << i << " " << dp[0][i] << ' ' << dp[1][i] << endl;
    for (int i = 1; i <= n; ++i) ans = max(ans, max(dp[0][i], dp[1][i]));
    cout << ans << endl;
    return 0;
}
