#include <iostream>
using namespace std;

int dp[2][20005], n, ans[10005];

void init() {
  dp[0][1] = 1; dp[1][1] = 1;
  for (int i = 2; i <= 10005; ++i) {
    for (int j = 2; j <= 2 * i - 1; ++j) {
      dp[i % 2][j] = (dp[i % 2][j - 1] + dp[(i - 1) % 2][j]) % 10000;
    }
    ans[i] = dp[i % 2][2 * i - 1];
  }
}

int main() {
  init();
  while (cin >> n, n) {
    if (n >= 7) printf("%04d\n", ans[n + 1]);
    else cout << ans[n + 1] << endl;
  }
  return 0;
}
