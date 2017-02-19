#include "lib1953.h"
#include <bits/stdc++.h>
using namespace std;

const int maxn = 500000 + 5;
struct Point { long double x, y; } ch[maxn];
long long Max, Min;
int m, n;

double cross(const Point&, const Point&, const Point&);

void init(int N, long long D[], long long U[]) {
  Max = LLONG_MIN, Min = LLONG_MAX;
  n = N; m = 0;
  for (int i = 0; i < N; ++i) {
    while (m >= 2 && cross(ch[m - 2], ch[m - 1], (Point){ (long double)i, (long double)D[i] }) <= 0) --m;
    ch[m++] = (Point){ (long double)i, (long double)D[i] };
  }
  for (int i = N - 1, t = m + 1; i >= 0; --i) {
    while (m >= t && cross(ch[m - 2], ch[m - 1], (Point){ (long double)i, (long double)U[i] }) <= 0) --m;
    ch[m++] = (Point){ (long double)i, (long double)U[i] };
  }
  for (int i = 0; i < N; ++i) Max = max(Max, U[i]), Min = min(Min, D[i]);
}

int query(long long a, long long b, long long c) {
  if (b < 0) a = -a, b = -b, c = -c;

  return 0;
}

double cross(const Point& a, const Point& b, const Point& c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
