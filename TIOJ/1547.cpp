#include <cstdio>
using namespace std;

inline int rit() {
  int t = 0, k = 1;
  char c;
  do {
    c = getchar();
    if (c == '-') k = -1;
  } while (c < '0' || c > '9');
  do {
    t = t * 10 + c - '0';
    c = getchar();
  } while (c >= '0' && c <= '9');
  return k * t;
}

int f[31];

int main() {
  int t = rit();
  f[1] = 1; f[2] = 2;
  for (int i = 3; i <= t; ++i) f[i] = f[i - 1] + f[i - 2];
  int prev = 0;
  int cur;
  for (int i = 1; i <= t; ++i) {
    for (int j = 0; j < f[i]; ++j) {
      if (prev == 0) {
        printf("1");
        prev = 1;
      } else if (prev == 1) {
        printf("2");
        prev = 2;
      } else {
        printf("0");
        prev = 0;
      }
    }
    printf("\n");
  }
  return 0;
}
