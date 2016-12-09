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

int N, pre[1005], A[1005], dpa[1005][1005], delta;
int dp(int, int);
int sum(int, int);

int main() {
  rit(N);
  for (int i = 0; i < N; ++i) rit(A[i]), pre[i] = pre[i - 1] + A[i];
  memset(dpa, 0, sizeof(dpa));
  printf("%d\n", 2 * dp(0, N - 1) - pre[N - 1]);
  return 0;
}

int dp(int L, int R) {
  // if (L == R) return A[L];
  if (dpa[L][R]) return dpa[L][R];
  int m = 0;
  for (int k = L + 1; k <= R; ++k) m = min(m, dp(k, R));
  for (int k = L; k < R; ++k) m = min(m, dp(L, k));
  return dpa[L][R] = pre[R] - pre[L - 1] - m;
}
