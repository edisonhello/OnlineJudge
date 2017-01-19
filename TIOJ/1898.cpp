#include "lib1898.h"
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 100000 + 5;
int dp[2][maxn];

int findSample(int n, int confidence[], int host[], int protocal[]) {
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; ++i) dp[0][i] = confidence[i];
  for (int i = n - 1; i > 0; --i) {
    int fa = host[i];
    if (protocal[i] == 0) {
      dp[0][fa] += dp[1][i];
      dp[1][fa] += max(dp[0][i], dp[1][i]);
    }
    if (protocal[i] == 1) {
      dp[0][fa] = max(dp[0][fa] + max(dp[0][i], dp[1][i]), dp[1][fa] + dp[0][i]);
      dp[1][fa] += dp[1][i];
    }
    if (protocal[i] == 2) {
      dp[0][fa] = max(dp[0][fa] + dp[1][i], dp[1][fa] + dp[0][i]);
      dp[1][fa] += dp[1][i];
    }
  }
  return max(dp[0][0], dp[1][0]);
}
