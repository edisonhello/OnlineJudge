#include <cstdio>
#include <algorithm>
#define getchar getchar_unlocked
using namespace std;

int dp[10010], n, t, mx, __t, i, j, k;
char __c;

struct Stone {
  int w, m, c;
};

Stone s[10010];

inline int rit() {
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
  for (i = 0; i < n; ++i) s[i].w = rit(), s[i].m = rit(), s[i].c = rit();
  t = rit();
  for (i = 0; i < n; ++i) {
    for (j = t; j >= s[i].w; --j) {
      mx = 0;
      for (k = 1; k <= s[i].c; ++k) {
        if (j - s[i].w * k < 0) break;
        mx = max(mx, dp[j - s[i].w * k] + s[i].m * k);
      }
      dp[j] = max(dp[j], mx);
    }
  }
  printf("%d\n", dp[t]);
  return 0;
}
