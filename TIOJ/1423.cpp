#include <cstdio>
#include <algorithm>
#ifdef linux
#define getchar getchar_unlocked
#endif
using namespace std;

char __c;
bool flag;

template <typename T>
inline bool rit(T& x) {
  __c = 0; flag = false;
  while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
  __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
  while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
  if (flag) x = -x;
  return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) {return rit(x) && rit(args...);}

struct XY {
  int x, y;
  int operator * (const XY& xy) const {
    return x * xy.y - xy.x * y;
  }
};

int N, neg, pos, cnt;
XY xy[350], nw1, nw2;

int main() {
  rit(N);
  for (int i = 0; i < N; ++i) rit(xy[i].x, xy[i].y);
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (i == j) continue;
      neg = 0, pos = 0;
      for (int k = 0; k < N; ++k) {
        if (k == i) continue;
        nw1 = {xy[i].x - xy[j].x, xy[i].y - xy[j].y};
        nw2 = {xy[i].x - xy[k].x, xy[i].y - xy[k].y};
        if (nw1 * nw2 > 0) pos++;
        else if (nw1 * nw2 < 0) neg++;
      }
      cnt += neg * pos;
    }
  }
  printf("%d\n", cnt);
}
