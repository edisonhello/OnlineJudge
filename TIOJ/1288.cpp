#include <cstdio>
#include <algorithm>
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

int tri[105][105], n, dpa[105][105];
int dp(int, int);

int main() {
  rit(n);
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= i; ++j) rit(tri[i][j]);
  printf("%d\n", dp(1, 1));
  return 0;
}

int dp(int i, int j) {
  if (i == n) return tri[i][j];
  if (dpa[i][j]) return dpa[i][j];
  return dpa[i][j] = tri[i][j] + max(dp(i + 1, j), dp(i + 1, j + 1));
}
