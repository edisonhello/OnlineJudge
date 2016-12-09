#include <iostream>
#include <cstring>

int n, m, cur;
long long dp[2][1<<14];

int main() {
  std::cin.tie(0); std::ios_base::sync_with_stdio(false);
  while (std::cin >> n >> m, (n || m)) {
    memset(dp, 0, sizeof(dp));
    if (n < m) std::swap(n, m);
    dp[0][(1<<m) - 1] = 1; cur = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cur ^= 1;
        memset(dp[cur], 0, sizeof(dp[cur]));
        for (int k = 0; k < (1<<m); ++k) {
          if ((k<<1) & (1<<m)) dp[cur][(k<<1) ^ (1<<m)] += dp[1 - cur][k];
          if (i && !(k & (1<<m - 1))) if (((k<<1) ^ (1<<m) ^ 1) & (1<<m)) dp[cur][((k<<1) ^ (1<<m) ^ 1) ^ (1<<m)] += dp[1 - cur][k];
          if (j && !(k & 1)) if (((k<<1) ^ 3) & (1<<m)) dp[cur][((k<<1) ^ 3) ^ (1<<m)] += dp[1 - cur][k];
        }
      }
    }
    std::cout << dp[cur][(1<<m) - 1] << '\n';
  }
  return 0;
}
