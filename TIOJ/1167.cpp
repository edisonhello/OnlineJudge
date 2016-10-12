#include <cstdio>
#include <algorithm>
#define getchar getchar_unlocked
using namespace std;

int n, k, a[1000010], __t, i;
char __c;

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
  while (true) {
    n = rit(), k = rit();
    if (n == 0 && k == 0) break;
    for (i = 0; i < n; ++i) a[i] = rit();
    sort(a, a + n);
    printf("%d\n", a[n - k]);
  }
  return 0;
}
