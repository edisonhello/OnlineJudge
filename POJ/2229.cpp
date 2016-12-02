#include <cstdio>
using namespace std;

int dp[1000005], N;

int main() {
  scanf("%d", &N);
  dp[0] = 1;
  for (int i = 0; (1 << i) <= N; ++i) {
    for (int j = (1 << i); j <= N; ++j) dp[j] += dp[j - (1 << i)], dp[j] %= (int)1e9;
  }
  // if (N >= 902) printf("%09d\n", dp[N]);
  // else printf("%d\n", dp[N]);
  printf("%d\n", dp[N]);
  return 0;
}
