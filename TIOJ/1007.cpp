#include <cstdio>
using namespace std;

unsigned long long DP[100][20], sum;
int n, m;

int main() {
  dp[0][0] = 1;
  dp[1][0] = 1;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    sum = dp[i][0];
    for (int j = 1; j <= n; ++j) {
        dp[i][j] = dp[i - 1][j - 1];
        sum += dp[i][j];
    }
    if (i == m) printf("%llu\n", sum);
    else dp[i + 1][0] = sum;
  }
  return 0;
}
