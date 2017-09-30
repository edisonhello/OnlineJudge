#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
const long long inf = 1e16 + 1;
int d[maxn], t[7][maxn], bst[2][maxn];
long long dp[2][maxn], s[maxn]; 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> d[i], s[i] = s[i - 1] + d[i];
    for (int i = 0; i < 2; ++i) for (int j = 0; j < maxn; ++j) dp[i][j] = -inf;
    dp[0][0] = 0;
    bst[0][0] = 0;
    int cur = 1;
    for (int i = 1; i <= k; ++i) {
        int ind = 0;
        fill(dp[cur], dp[cur] + maxn, -inf);
        fill(bst[cur], bst[cur] + maxn, 0);
        for (int j = 1; j <= n; ++j) {
            if (!(i & 1)) {
                dp[cur][j] = dp[cur ^ 1][bst[cur ^ 1][j - 1]] - s[j] + s[bst[cur ^ 1][j - 1]];
                t[i][j] = bst[cur ^ 1][j - 1];
            } else {
                dp[cur][j] = dp[cur ^ 1][bst[cur ^ 1][j - 1]] + s[j] - s[bst[cur ^ 1][j - 1]];
                t[i][j] = bst[cur ^ 1][j - 1];
            }
            bst[cur][j] = bst[cur][j - 1];
            if (cur == 1) { if (dp[cur][j] + s[j] > dp[cur][bst[cur][j]] + s[bst[cur][j]]) bst[cur][j] = j; }
            else { if (dp[cur][j] - s[j] > dp[cur][bst[cur][j]] - s[bst[cur][j]]) bst[cur][j] = j; }
        }
        cur ^= 1;
    }
    int now = n;
    for (int i = k; i >= 2; --i) {
        cout << t[i][now] << endl;
        now = t[i][now];
    }
    return 0;
}
