#include <cstdio>
#include <cstring>
#define getchar getchar_unlocked
using namespace std;

int x, ff[360001], hh[360001], gg[360001], __t;
short __k;
char __c;
int f(int);
int h(int);
int g(int);

int f(int x) {
  // printf("f(%d)\n", x);
  if (ff[x + 300]) return ff[x + 300];
  if (x > h(x)) return ff[x + 300] = f(x - 1) - h(x);
  if (x < h(x)) return ff[x + 300] = f(g(x)) - g(x);
  else return ff[x + 300] = 1;
}

int h(int y) {
  // printf("h(%d)\n", y);
  if (hh[y + 300]) return hh[y + 300];
  if (y < 2) return hh[y + 300] = -1;
  return hh[y + 300] = 2 + h(y - 1) - h(y - 2);
}

int g(int z) {
  // printf("g(%d)\n", z);
  if (gg[z + 300]) return gg[z + 300];
  if (z <= 2) return gg[z + 300] = z * z - 1;
  return gg[z + 300] = 2;
}

inline int rit() {
  __t = 0; __k = 1;
  do {
    __c = getchar();
    if (__c == '-') __k = -1;
  } while (__c < '0' || __c > '9');
  do {
    __t = __t * 10 + __c - '0';
    __c = getchar();
  } while (__c >= '0' && __c <= '9');
  return __t * __k;
}

int main() {
  x = rit();
  memset(ff, 0, sizeof(ff)), memset(gg, 0, sizeof(gg)), memset(hh, 0, sizeof(hh));
  printf("%d\n", f(x));
  return 0;
}
