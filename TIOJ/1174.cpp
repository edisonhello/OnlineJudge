#include <cstdio>
#include <algorithm>
using namespace std;

int A[100000], B, m, n, r, l, md, i, mn = 1e9, t, k;
char c;
int bs();

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
  n = rit(); m = rit();
  for (i = 0; i < n; ++i) A[i] = rit();
  sort(A, A + n);
  for (i = 0; i < m; ++i) {
    B = rit();
    mn = min(mn, abs(B - A[bs()]));
  }
  printf("%d\n", mn);
  return 0;
}

int bs() {
  r = n - 1;
  l = 0;
  md = (l + r) / 2;
  while (l < r) {
    if (A[md] > B) r = md - 1;
    else if (A[md] < B) l = md + 1;
    else return md;
    md = (l + r) / 2;
  }
  return l;
}
