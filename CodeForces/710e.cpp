#include <iostream>
#include <algorithm>
using namespace std;

long long int dp[10000001];

int main() {
  long long int n, x, y;
  cin >> n >> x >> y;
  dp[1] = x;
  for (long long int i = 2; i <= n; ++i) {
    if (i % 2 == 0) {
      dp[i] = min(dp[i - 1] + x, dp[i / 2] + y);
    } else {
      dp[i] = min(dp[i - 1] + x, dp[i / 2] + y + x);
    }
  }
  cout << dp[n] << endl;
  return 0;
}
