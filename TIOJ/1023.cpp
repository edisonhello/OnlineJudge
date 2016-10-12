#include <cstdio>
#include <algorithm>
#define getchar getchar_unlocked
using namespace std;

int blue[50010], red[50010], m, __t;
char __c;
long long cnt;

inline int rit() {
  __t = 0;
  do {
    __c = getchar();
  } while (__c < '0' || __c > '9');
  do {
    __t = __t * 10 + __c - '0';
    __c = getchar();
  } while (__c >= '0' && __c <= '9');
  return __t;
}

int main() {
  while (scanf("%d", &m) != EOF) {
    for (int i = 0; i < m; ++i) blue[i] = rit();
    for (int i = 0; i < m; ++i) red[i] = rit();
    sort(blue, blue + m); sort(red, red + m);
    cnt = 0;
    for (int i = 0; i < m; ++i) cnt += red[i] * blue[i];
    printf("%lld\n", cnt);
  }
  return 0;
}
