#include <cstdio>
#include <set>
#include <algorithm>
#define getchar getchar_unlocked
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

struct Point {
  int x, y;
  bool operator<(const Point& res) const {
    return x == res.x ? y < res.y : x < res.x;
  }
};

multiset<Point> S;
multiset<Point>::iterator it;
int N, x, y, T, kase;

int main() {
  rit(T);
  for (kase = 1; kase <= T; ++kase) {
    if (kase > 1) printf("\n");
    printf("Case #%d:\n", kase);
    rit(N);
    S.clear();
    while (N--) {
      rit(x, y);
      Point p = (Point){ x, y };
      it = S.lower_bound(p);
      if (it == S.begin() || (--it)->y > p.y) {
        S.insert(p);
        it = S.upper_bound(p);
        while (it != S.end() && it->y >= p.y) S.erase(it++);
      }
      printf("%d\n", S.size());
    }
  }
  return 0;
}
