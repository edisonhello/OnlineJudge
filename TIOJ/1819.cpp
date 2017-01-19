#include <cstdio>
#include <unordered_set>
#define getchar gtx
using namespace std;

char __c;
bool flag;

inline int gtx() {
  const int N = 1048576;
  static char buffer[N];
  static char *p = buffer, *end = buffer;
  if (p == end) {
    if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
    p = buffer;
  }
  return *p++;
}

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

using namespace std;

unordered_set<double> s;
int N, M, Max, L, R;

inline void ins(double);

int main() {
  rit(N, M);
  for (int i = 0; i < N; ++i) {
    rit(L, R);
    if (L > R) swap(L, R);
    ins(L - 0.5); ins(R + 0.5);
    Max = max(Max, (int)s.size());
  }
  printf("%d\n", Max / 2);
  return 0;
}

inline void ins(double x) {
  if (!s.count(x)) s.insert(x);
  else s.erase(x);
}
