#include <cstdio>
using namespace std;

short n, nn, t;
char c;

inline int rit() {
  t = 0;
  do {
    c = getchar_unlocked();
  } while (c < '0' || c > '9');
  do {
    t = t * 10 + c - '0';
    c = getchar_unlocked();
  } while (c >= '0' && c <= '9');
  return t;
}

int main() {
  n = rit();
  while (n--) {
    nn = rit();
    printf("%i\n", nn % 2);
  }
  return 0;
}
