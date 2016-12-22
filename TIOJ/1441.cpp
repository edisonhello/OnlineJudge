#include <cstdio>
#define getchar getchar_unlocked
using namespace std;

int pre, a, N, len;
bool b, flag;
char __c;

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

int main() {
  pre = -1;
  rit(N);
  b = true;
  for (int i = 0; i < N; ++i) {
    rit(a);
    if (b) { if (a > pre) len++, b = !b; }
    else { if (a < pre) len++, b = !b; }
    pre = a;
  }
  if (b) len--;
  printf("%d\n", len);
}
