#include <cstdio>
#include <algorithm>
#include <cstdlib>
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

int N, a[200005], dp[200005];

int main() {
  rit(N);
  for (int i = 0; i < N; ++i) rit(a[i]);
  dp[0] = 0; dp[1] = abs(a[1] - a[0]);
  for (int i = 2; i < N; ++i) {
    dp[i] = min(dp[i - 2] + abs(a[i] - a[i - 2]), dp[i - 1] + abs(a[i] - a[i - 1]));
  }
  printf("%d\n", dp[N - 1]);
  return 0;
}
