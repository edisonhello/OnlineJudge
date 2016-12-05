#include <cstdio>
#define getchar getchar_unlocked
using namespace std;

char __c; bool flag;
template <typename T>
inline bool rit(T& x) {
  __c = 0, flag = false;
  while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
  __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
  while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
  if (flag) x = -x;
  return true;
}
template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

unsigned long long dp[100][20], sum;
int n, m;

int main() {
  dp[0][0] = 1; dp[1][0] = 1;
  rit(n, m);
  for (int i = 1; i <= m; ++i) {
    sum = dp[i][0];
    for (int j = 1; j <= n; ++j) dp[i][j] = dp[i - 1][j - 1], sum += dp[i][j];
    if (i == m) printf("%llu\n", sum);
    else dp[i + 1][0] = sum;
  }
  return 0;
}
