#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;
int dp[3][maxn];
vector<int> G[maxn];

void dfs(int now, int fa) {
    dp[0][now] = 1; 
    int tmp = 0;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now);
        dp[0][now] += min(dp[0][u], dp[1][u]);
        dp[1][now] += dp[2][u];
        tmp += dp[2][u];
    }
    dp[2][now] = maxn;
    for (int u : G[now]) if (u != fa) {
        dp[2][now] = min(dp[2][now], tmp - dp[2][u] + dp[0][u]);
    }
    // for (int i = 0; i < 3; ++i) {
        // cout << "dp[" << i << "][" << now << "] = " << dp[i][now] << endl;
    // }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n) {
        for (int i = 0; i < maxn; ++i) G[i].clear();
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n - 1; ++i) {
            int a, b; cin >> a >> b;
            G[a].push_back(b); G[b].push_back(a);
        }
        dfs(1, 0);
        cout << min(dp[0][1], dp[2][1]) << endl;
        int z; cin >> z;
        if (z == -1) break;
    }
    return 0;
}
