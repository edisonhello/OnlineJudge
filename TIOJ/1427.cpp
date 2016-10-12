#include <iostream>
#include <string>
#include <algorithm>
#define getchar getchar_unlocked
using namespace std;

int dp[2][5001][10][2], ans, n, m, k, tmp, jizz, __t, i, j, t;
char __c;
string s1, s2;

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
  n = rit(), m = rit(), k = rit();
  cin >> s1 >> s2;
  ans = 0;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      tmp = (s1[i] == s2[j]) ? 1 : 0;
      for (t = 0; t < k; ++t) {
        dp[(i + 1) % 2][j + 1][t][0] = max(dp[i % 2][j + 1][t][0], dp[(i + 1) % 2][j][t][0]);
        dp[(i + 1) % 2][j + 1][t][0] = max(dp[(i + 1) % 2][j + 1][t][0], dp[(i + 1) % 2][j][t][1]);
        dp[(i + 1) % 2][j + 1][t][0] = max(dp[(i + 1) % 2][j + 1][t][0], dp[i % 2][j + 1][t][1]);
      }
      if (tmp) {
        jizz = (s1[i] == 'a') ? 1 : 0;
        for (t = 0; t < k; ++t) {
          dp[(i + 1) % 2][j + 1][t][1] = jizz + dp[i % 2][j][t][1];
          if (t) dp[(i + 1) % 2][j + 1][t][1] = max(dp[(i + 1) % 2][j + 1][t][1], jizz + dp[i % 2][j][t - 1][0]);
          ans = max(ans, dp[(i + 1) % 2][j + 1][t][1]);
        }
      }
    }
    for (j = 0; j < m; ++j) for (t = 0; t < k; ++t) dp[i % 2][j][t][0] = dp[i % 2][j][t][1] = 0;
  }
  printf("%d\n", ans * 2);
  return 0;
}
