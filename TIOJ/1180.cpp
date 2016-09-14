#include <cstdio>
using namespace std;

inline int rit() {
  int t = 0;
  char c;
  do {
    c = getchar();
  } while (c < '0' || c > '9');
  do {
    t = t * 10 + c - '0';
    c = getchar();
  } while (c >= '0' && c <= '9');
  return t;
}
int main() {
  int n, N;
  long long int t;
  N = rit();
  for (int j = 0; j < N; ++j) {
    t = 1;
    n = rit();
    printf("Case #%d:\n", j + 1);
    printf("TFCIS%d=%lld\n", 0, t);
    for (int i = 1; i <= n; ++i) {
      t *= i;
      printf("TFCIS%d=%lld\n", i, t);
    }
  }
  return 0;
}
