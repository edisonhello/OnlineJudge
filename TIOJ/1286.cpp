#include <iostream>
using namespace std;

int a, b, c, d, ret, t, i;
char cc;
const int MOD = 1000000;

int _pow(int base, int p) {
  int ans = 1;
  for (int i = 0; i < p; ++i) {
    ans *= base;
    ans %= MOD;
  }
  return ans;
}

inline int rit() {
  t = 0;
  do {
    cc = getchar_unlocked();
  } while (cc < '0' || cc > '9');
  do {
    t = t * 10 + cc - '0';
    cc = getchar_unlocked();
  } while (cc >= '0' && cc <= '9');
  return t;
}

int main() {
  a = rit(), b = rit(), c = rit(), d = rit();
  ret = 0;
  for (i = a; i <= d; i += b) {
    ret += _pow(i, c) % MOD;
  }
  printf("%d\n", ret % MOD);
  return 0;
}
