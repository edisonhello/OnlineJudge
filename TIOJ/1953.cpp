#include "lib1953.h"
#include <bits/stdc++.h>
using namespace std;

long long *d, *u;
int n;

void init(int N, long long D[], long long U[]) {
  n = N;
  d = D;
  u = U;
}

int query(long long a, long long b, long long c) {
  c = -c;
  long double dis;
  for (int i = 0; i < n; ++i) {
    if (-c >= d[i] && -c <= u[i]) return 1;
    if ()
  }
  return 0;
}
