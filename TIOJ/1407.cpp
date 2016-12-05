#include <cstdio>
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

const int N = 100000;
int n, w[N + 5], m[N + 5], c[N + 5], T, dp[1000005], num;

int main() {
  rit(n); for (int i = 0; i < n; ++i) rit(w[i], m[i], c[i]);
  rit(T);
  for (int i = 0; i < n; ++i) {
    num = min(c[i], T / w[i]);
    for (int k = 1; num > 0; k *= 2) {
      if (k > num) k = num;
      num -= k;
      for (int j = T; j >= w[i] * k; --j) {
        dp[j] = max(dp[j], dp[j - w[i] * k] + m[i] * k);
      }
    }
  }
  printf("%d\n", dp[T]);
  return 0;
}
