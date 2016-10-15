#include <iostream>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;

int n, p, w[101];
long long dp[10010];

int main() {
  while (cin >> n >> p, (n || p)) {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) cin >> w[i];
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 1; j <= p; ++j) {
        if (j - w[i] >= 0) dp[j] += dp[j - w[i]];
      }
    }
    cout << dp[p] << endl;
  }
  return 0;
}
