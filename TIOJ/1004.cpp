#include <cstdio>
#define getchar getchar_unlocked
using namespace std;

int N, __t, now;
char __c;

inline int rit() {
  __t = 0;
  do {
    __c = getchar();
  } while (__c < '0' && __c > '9');
  do {
    __t = __t * 10 + __c - '0';
    __c = getchar();
  } while (__c >= '0' && __c <= '9');
  return __t;
}

int main() {
  N = rit();
  now = 0;
  for(int Ni = 3; Ni <= N; Ni++) now += 2, now %= Ni;
  printf("%d\n", now + 1);
}
