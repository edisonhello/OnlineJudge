#include <cstdio>
#include <algorithm>
using namespace std;

int n, a[1005], dpa[1005][1005], tot, ans;
int dp(int, int);
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
inline bool rit(T& x, Args& ...args) {return rit(x) && rit(args...);}

int main() {
  rit(n);
  for (int i = 0; i < n; ++i) rit(a[i]), tot += a[i];
  ans = dp(0, n - 1);
  printf("%d %d\n", (tot - ans) / 2 + ans, (tot - ans) / 2);
  return 0;
}

int dp(int L, int R) {
  if (L == R) return a[L];
  if (L > R) return 0;
  if (dpa[L][R]) return dpa[L][R];
  return dpa[L][R] = max(a[L] - dp(L + 1, R), a[R] - dp(L, R - 1));
}
