#include <cstdio>
#include <cstring>
#include <algorithm>
#define getchar getchar_unlocked
using namespace std;

long long int dp[2005], n, m, hi[2005], ci[2005], k, mx, __t;
char __c;

inline long long int rit() {
  __t = 0;
  do {
    __c = getchar();
  } while (__c < '0' || __c > '9');
  do {
    __t = __t * 10 + __c - '0';
    __c = getchar();
  } while (__c >= '0' && __c <= '9');
  return __t;
}

int main() {
  n = rit(), m = rit();
  for (int i = 0; i < n; ++i) hi[i] = rit(), ci[i] = rit();
  for (int i = 0; i < n; ++i) {
    for (int j = ci[i]; j <= m; ++j) {
      dp[j] = max(dp[j], dp[j - ci[i]] + hi[i]);
    }
  }
  printf("%lld\n", dp[m]);
  return 0;
}
