#include <iostream>
#include <algorithm>
using namespace std;

long long cnt;
int r[50010], b[50010], m, __t;

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
  while (scanf("%d", &m) != EOF) {
    for (int i = 0; i < m; ++i) r[i] = rit();
    for (int i = 0; i < m; ++i) b[i] = rit();
    sort(r, r + m, [](long long a, long long b) -> bool {return a < b;});
    sort(b, b + m, [](long long a, long long b) -> bool {return a > b;});
    cnt = 0;
    for (int i = 0; i < m; ++i) {
      cnt += r[i] * b[i];
    }
    printf("%lld\n", cnt);
  }
  return 0;
}
