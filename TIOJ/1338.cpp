#include "lib1338.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;

struct Node {
  long long gcd, mn;
};

int n, d, p;
long long* c;
Node table[21][1000005];
Node L, R;
void __build();

void __build() {
  for (int i = 0; i < n; ++i) table[0][i].gcd = c[i], table[0][i].mn = c[i];
  for (int i = 1; (1 << i) - 1 < n; ++i) {
    for (int j = 0; j + (1 << i) - 1 < n; ++j) {
      L = table[i - 1][j]; R = table[i - 1][j + (1 << (i - 1))];
      table[i][j].mn = min(L.mn, R.mn);
      table[i][j].gcd = __gcd(L.gcd, R.gcd);
    }
  }
}

void init(int N, long long C[]) {
  n = N; c = C;
  __build();
}

int query(int l, int r) {
  d = r - l;
  p = 31 - __builtin_clz(d);
  L = table[p][l]; R = table[p][r - (1 << p)];
  return __gcd(L.gcd, R.gcd) == min(L.mn, R.mn);
}
