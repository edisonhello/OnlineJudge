#include <iostream>
using namespace std;

int T, n, dp[4][10000];

void init() {
  dp[0][1] = 0; dp[1][1] = 1; dp[2][1] = 1; dp[3][1] = 1;
  for (int i = 2; i < 10000; ++i) {
    dp[0][i] = dp[1][i - 1] + dp[2][i - 1] + dp[3][i - 1];
    dp[1][i] = dp[0][i - 1] + dp[2][i - 1] + dp[3][i - 1];
    dp[2][i] = dp[0][i - 1] + dp[1][i - 1] + dp[3][i - 1];
    dp[3][i] = dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1];
  }
}
int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  init();
  cin >> T;
  while (T--) {
    cin >> n;
    cout << dp[0][n] << '\n';
  }
  return 0;
}
