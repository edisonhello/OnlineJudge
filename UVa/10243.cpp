#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int dp[2][maxn], N, k, u;
vector<int> G[maxn];

void DP(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  while (cin >> N, N) {
    for (int i = 0; i < maxn; ++i) G[i].clear();
    fill(dp[0], dp[0] + maxn, INT_MAX);
    fill(dp[1], dp[1] + maxn, INT_MAX);
    for (int i = 1; i <= N; ++i) {
      cin >> k;
      while (k--) cin >> u, G[i].push_back(u);
    }
    DP(1, 0);
    if (N == 1) cout << "1\n";
    else cout << min(dp[0][1], dp[1][1]) << '\n';
  }
  return 0;
}

void DP(int x, int fa) {
  dp[0][x] = 1;
  dp[1][x] = 0;
  for (int u : G[x]) if (u != fa) {
    DP(u, x);
    dp[0][x] += min(dp[0][u], dp[1][u]);
    dp[1][x] += dp[0][u];
  }
}
