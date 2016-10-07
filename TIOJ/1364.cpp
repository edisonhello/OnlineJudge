#include <algorithm>
#include <cstdio>
using namespace std;

int n, k, a[1000010], __t, __k;
char __c;

inline int rit() {
  __t = 0; __k = 1;
  do {
    __c = getchar_unlocked();
    if (__c == '-') __k = -1;
  } while (__c < '0' || __c > '9');
  do {
    __t = __t * 10 + __c - '0';
    __c = getchar_unlocked();
  } while (__c >= '0' && __c <= '9');
  return __t * __k;
}

int main() {
  while (scanf("%d %d", &n, &k) != EOF) {
    for (int i = 0; i < n; ++i) a[i] = rit();
    sort(a, a + n, [](const int& a, const int& b) -> bool {return a > b;});
    printf("%d\n", a[k - 1]);
  }
  return 0;
}
