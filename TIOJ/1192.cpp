#include <cstdio>
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

int T, n, djs[2000005], x, pre;

inline int front(int x) { return x * 2; }
inline int back(int x) { return x * 2 + 1; }

int F(int x) { return djs[x] == x ? x : djs[x] = F(djs[x]); }

void U(int x, int y) {
  x = F(x); y = F(y);
  djs[x] = y;
}

int main() {
  rit(T);
  while (T--) {
    rit(x); pre = x;
    while (rit(x), x) {
      if (F(front(x)) == F(back(pre)) || F(back(x)) == F(front(pre))) { p = false; break; }
      U(front(x), front(pre)); U(back(x), back(pre));
      pre = x;
    }
    if ()
  }
}
