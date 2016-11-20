#include <iostream>
#include <cstring>
using namespace std;

long long int dp[41];

int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    memset(dp, 0, sizeof(dp));
    dp[1] = 1;
    dp[2] = 5;
    dp[3] = 11;
    for (int i = 4; i <= n; ++i) dp[i] = dp[i - 1] + 4 * dp[i - 2] + dp[i - 3] * 2;
    cout << dp[n] << endl;
  }
  return 0;
}
