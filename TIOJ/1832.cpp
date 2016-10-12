#include <cstdio>
#define getchar getchar_unlocked
using namespace std;

long long int __t, hi, n, q, l, r, h[1000010];
char __c;

inline long long int rit() {
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
  n = rit(), q = rit();
  h[0] = 0;
  for (int i = 1; i <= n; ++i) hi = rit(), h[i] = hi ^ h[i - 1];
  for (int i = 0; i < q; ++i) {
    l = rit(), r = rit();
    printf("%lld\n", h[r] ^ h[l - 1]);
  }
  return 0;
}
