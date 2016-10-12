#include <cstdio>
#include <cstring>
#define getchar getchar_unlocked
using namespace std;

int mp[200][200], m, n, dp[200][200], s[200], value, lm, i, j, k;
int mx;
short __t;
char __c;

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
  m = rit(), n = rit();
  for (i = 0; i < m; ++i) for (j = 0; j < n; ++j) mp[i][j] = rit();
  for (j = 0; j < n; ++j) {
    for (i = 0; i < m; ++i) {
      dp[i][j] = (i == 0) ? mp[i][j] : mp[i][j] + dp[i - 1][j];
    }
  }
  mx = 0;
  for (i = 0; i < m; ++i) {
    for (j = i; j < m; ++j) {
      memset(s, 0, sizeof(s));
      lm = 0;
      s[0] = (i == 0) ? dp[j][0] : dp[j][0] - dp[i - 1][0];
      if (s[0] != j - i + 1) s[0] = 0;
      for (k = 1; k < n; ++k) {
        value = (i == 0) ? dp[j][k] : dp[j][k] - dp[i - 1][k];
        if (value == j - i + 1) s[k] = s[k - 1] + value;
        else s[k] = 0;
        if (s[k] > s[lm]) lm = k;
      }
      if (s[lm] > mx) mx = s[lm];
    }
  }
  printf("%d\n", mx);
  return 0;
}
