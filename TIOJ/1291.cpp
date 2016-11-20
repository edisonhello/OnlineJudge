#include <iostream>
using namespace std;

int dp[205][205], n, m, ans;
const int MOD = 1000000;
void init();

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  init();
  while (cin >> n >> m, (n || m)) {
    ans = 0; for (int i = 1; i <= n; ++i) ans += dp[m][i], ans %= MOD;
    cout << ans << '\n';
  }
  return 0;
}

void init() {
  dp[0][0] = 1;
  for (int i = 1; i < 205; ++i) {
    for (int j = 1; j <= i; ++j) {
      dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] * j) % MOD;
    }
  }
}
