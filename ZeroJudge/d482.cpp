#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char __c;
bool flag;

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

int dp[101][101], N, mp[101][101];

int main() {
  while (rit(N)) {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) rit(mp[i][j]);
    dp[0][0] = mp[0][0];
    for (int i = 1; i < N; ++i) dp[0][i] = mp[0][i] + dp[0][i - 1];
    for (int i = 1; i < N; ++i) {
      dp[i][0] = mp[i][0] + dp[i - 1][0];
      for (int j = 1; j < N; ++j) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + mp[i][j];
    }
    printf("%d\n", dp[N - 1][N - 1]);
  }
  return 0;
}
