#include <cstdio>
#include <deque>
#include <algorithm>
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

const int maxn = 1000000 + 5;
struct S {
  int x, d, id;
  bool operator<(const S& rhs) const {
    return x < rhs.x;
  }
} s[maxn];

deque<S> dq;
int N, L, a, b, Max, D;

int main() {
  rit(N, L);
  for (int i = 0; i < N; ++i) rit(s[i].x, s[i].d), s[i].id = i;
  sort(s, s + N);
  for (int i = 0; i < N; ++i) {
    int t;
    if (s[i].d == 0) t = s[i].x + 1;
    else t = L - s[i].x + 1;
    if (t > Max) Max = t, D = s[i].d;
  }
  for (int i = N - 1; i >= 0; --i) {
    dq.push_front(s[i]);
    if (s[i].d == 1) dq.pop_back();
  }
  a = dq.back().id;
  dq.clear();
  for (int i = 0; i < N; ++i) {
    dq.push_front(s[i]);
    if (s[i].d == 0) dq.pop_back();
  }
  b = dq.back().id;
  printf("%d\n", (D ? b : a));
  return 0;
}
