#include <cstdio>
#include <cstring>
#include <algorithm>
#define getchar getchar_unlocked
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
int N, M, a, dp[2][10005], ans;

int main() {
  while (rit(N, M), (N || M)) {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; ++i) {
      rit(a);
      for (int j = 0; j < M; ++j) {
        if (!j || dp[i % 2][j]) dp[(i + 1) % 2][(j * 10 + a) % M] = max(dp[(i + 1) % 2][(j * 10 + a) % M], dp[i % 2][j] + 1);
      }
      memcpy(dp[i % 2], dp[(i + 1) % 2], sizeof(dp[i % 2]));
    }
    ans = 0;
    for (int i = 0; i < M; ++i) {
      if (__gcd(i, M) == 1) ans = max(ans, dp[N % 2][i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
