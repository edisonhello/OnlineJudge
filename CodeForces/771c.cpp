#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
long long dp[5][maxn];
int n, k;
vector<int> G[maxn];

void dfs(int now, int fa) {
    dp[0][now] = 0;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now);
        for (int i = 0; i < k; ++i) {
            dp[(i + 1) % k][now] += dp[i][u];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    dfs(1, 0);
}
