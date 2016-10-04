#include <cstdio>
#include <bitset>
#include <algorithm>
#define MOD (int)(1e9 + 7)
using namespace std;

int djs[2000010], sz[2000010];
bitset<2000010> jizz;

int F(int x) {return (djs[x] == x) ? x : (djs[x] = F(djs[x]));}
int n, m, a, b, d, i, total, t;
long long int ret;
char c;
void U(int, int);
long long int _pow(int, int);
inline int rit();

int main() {
  n = rit(), m = rit();
  total = 0;
  fill(sz, sz + n * 2, 1);
  for (i = 0; i < 2 * n; ++i) djs[i] = i;
  for (i = 0; i < m; ++i) {
    a = rit(), b = rit(), d = rit();
    if (d == 1) {
      if (F(a * 2) == F(b * 2 + 1) || F(a * 2 + 1) == F(b * 2)) {printf("0\n"); return 0;}
      U(a * 2, b * 2);
      U(a * 2 + 1, b * 2 + 1);
    } else {
      if (F(a * 2) == F(b * 2) || F(a * 2 + 1) == F(b * 2 + 1)) {printf("0\n"); return 0;}
      U(a * 2, b * 2 + 1);
      U(a * 2 + 1, b * 2);
    }
  }
  for (i = 0; i < 2 * n; ++i) {
    if (!jizz[F(i)]) {total++; jizz[F(i)] = true;}
  }
  printf("%lld\n", _pow(2, total / 2 - 1));
  return 0;
}

void U(int x, int y) {
  x = F(x), y = F(y);
  if (sz[x] > sz[y]) swap(x, y);
  djs[x] = y;
  sz[y] += sz[x];
}

long long int _pow(int base, int p) {
  ret = 1;
  for (i = 0; i < p; ++i) {
    ret <<= 1;
    ret %= MOD;
  }
  return ret;
}

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
