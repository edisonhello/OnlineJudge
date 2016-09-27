#include <cstdio>
using namespace std;

double t, k, a, b, c;
char cc;

inline double rit() {
  t = 0, k = 1;
  do {
    cc = getchar_unlocked();
    if (cc == '-') k = -1;
  } while (cc < '0' || cc > '9');
  do {
    t = t * 10 + cc - '0';
    cc = getchar_unlocked();
  } while (cc >= '0' && cc <= '9');
  return t * k;
}

int main() {
  a = rit(); b = rit(); c = rit();
  // printf("%lf %lf %lf", a, b, c);
  if (c - b == b - a) if (c / b == b / a) printf("both\n"); else printf("arithmetic\n");
  else if (c / b == b / a) printf("geometric\n");
  else printf("normal");
}
