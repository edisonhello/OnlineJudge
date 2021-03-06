#include <cstdio>
#include <algorithm>
#define getchar getchar_unlocked
using namespace std;

unsigned a, b, __t;
char __c;
int cnt;

inline unsigned rit() {
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
  a = rit(), b = rit();
  cnt = 0;
  while (a != b) {
    if (a < b) swap(a, b);
    a /= 2;
    cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}
