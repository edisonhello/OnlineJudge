#include <cstdio>
#include <cstring>
#define getchar getchar_unlocked
using namespace std;

int n, a, sm[21], cnt, __t;
bool p[100010], jizz;
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
  while (n = rit(), n) {
    memset(sm, 0, sizeof(sm));
    for (int i = 0; i < n; ++i) a = rit(), sm[i] = sm[i - 1] + a;
    memset(p, false, sizeof(p));
    cnt = 0;
    if (sm[n - 1] == n) {printf("NO\n"); continue;}
    for (int i = 1; i <= n; ++i) {
      for (int j = i - 1; j < n; ++j) {
        if (!p[sm[j] - sm[j - i]]) {
          p[sm[j] - sm[j - i]] = true;
          cnt++;
        }
      }
    }
    if (cnt == sm[n - 1]) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
