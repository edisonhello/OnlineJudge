#include "lib1338.h"
#include <algorithm>
#include <cmath>
using namespace std;

struct Node {
  long long gcd, mn;
};

int n;
long long *c;
Node table[20][1000010];
void build();

void init(int N, long long C[]) {
  n = N, c = C;
  build();
}

int query(int L, int R) {
  int d = abs(R - L) + 1;
  int p = floor(log2(d));
  if (table[p + 1][L].mn == table[p + 1][L].gcd) return 1;
  return 0;
}

void build() {
  for (int i = 0; i < n; ++i) table[0][i].gcd = c[i], table[0][i].mn = c[i];
  for (int i = 1; (1 << i) - 1 < n; ++i) {
    for (int j = 0; j + (1 << i) - 1 < n; ++j) {
      Node n1 = table[i - 1][j], n2 = table[i - 1][j + (1 << i) - 1];
      table[i][j].gcd = __gcd(n1.gcd, n2.gcd);
      table[i][j].mn = min(n1.mn, n2.mn);
    }
  }
}
