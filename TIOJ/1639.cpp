#include <cstdio>
#define getchar getchar_unlocked
using namespace std;

long long int dp[4005][4005], p[4005], n, jizz[4005], __t, tmp;
char __c;
int h[4005][4005], mmm;

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
  n = rit();
  for (int i = 0; i < n; ++i) {p[i] = rit(); jizz[i] = (i == 0 ? p[i] : jizz[i - 1] + p[i]);}
  for (int i = n - 1; i >= 0; --i) {
    for (int j = i; j < n; ++j) {
      if (i == j) dp[i][j] = p[i], h[i][j] = i;
      else {
        dp[i][j] = 1ll << 60;
        for (int k = h[i][j - 1]; k <= h[i + 1][j]; ++k) {
          tmp = dp[i][k] + dp[k + 1][j] + jizz[j] - jizz[i - 1];
          if (dp[i][j] > tmp) {
            dp[i][j] = tmp;
            h[i][j] = k;
          }
        }
      }
    }
  }
  printf("%lld\n", dp[0][n - 1] - jizz[n - 1]);
  return 0;
}
