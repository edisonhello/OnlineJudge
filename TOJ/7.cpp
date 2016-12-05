#include <iostream>
using namespace std;

long long dp[2][25], n, T;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n + 1; ++i) cin >> dp[1][i];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n - i; ++j) dp[i % 2][j] = dp[(i + 1) % 2][j + 1] - dp[(i + 1) % 2][j];
    }
    if (n & 1) cout << dp[0][0] << '\n';
    else cout << dp[1][0] << '\n';
  }
  return 0;
}
