#include <iostream>
using namespace std;

int dp[2][20005], n, ans[10005];

void init() {
  dp[0][1] = 1; dp[1][1] = 1;
  // ans[1] = 1;
  for (int i = 2; i <= 10005; ++i) {
    // dp[i][1] = 1;
    for (int j = 2; j <= 2 * i - 1; ++j) {
      dp[i % 2][j] = (dp[i % 2][j - 1] + dp[(i - 1) % 2][j]) % 10000;
    }
    // for (int j = 1; j <= 2 * i - 1; ++j) cout << dp[i][j] << ' ';
    // cout << endl;
    // cout << dp[i][2 * i - 1] << endl;
    ans[i] = dp[i % 2][2 * i - 1];
  }
}

int main() {
  init();
  // for (int i = 1; i <= 9; ++i) cout << ans[i] << ' ';
  while (cin >> n, n) {
    if (n >= 7) printf("%04d\n", ans[n + 1]);
    else cout << ans[n + 1] << endl;
  }
  return 0;
}
