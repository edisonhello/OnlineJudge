#include <cstdio>
#include <algorithm>
using namespace std;

int a[100000], t, k, n, i;
char c;

inline int rit() {
  t = 0, k = 1;
  do {
    c = getchar_unlocked();
    if (c == '-') k = -1;
  } while (c < '0' || c > '9');
  do {
    t = t * 10 + c - '0';
    c = getchar_unlocked();
  } while (c >= '0' && c <= '9');
  return t * k;
}

int main() {
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; ++i) a[i] = rit();
    sort(a, a + n);
    for (i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");
  }
  return 0;
}
