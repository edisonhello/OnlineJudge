#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point {
  long long x, y;
  long long operator*(const Point& p) const {
    return x * p.y - y * p.x;
  }
  Point operator-(const Point& p) const {
    return {x - p.x, y - p.y};
  }
};

long long cross(const Point& o, const Point& a, const Point& b) {
  return (a - o).x * (b - o).y - (a - o).y * (b - o).x;
}

Point p[100005], ch[100005];
long long n, m;
double area;

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;
  sort(p, p + n, [](const Point& a, const Point& b) -> bool { return a.x == b.x ? a.y < b.y : a.x < b.x; });
  m = 0;
  for (int i = 0; i < n; ++i) {
    while (m >= 2 && cross(ch[m - 2], ch[m - 1], p[i]) < 0) m--;
    ch[m++] = p[i];
  }
  for (int i = n - 2, t = m + 1; i >= 0; --i) {
    while (m >= t && cross(ch[m - 2], ch[m - 1], p[i]) < 0) m--;
    ch[m++] = p[i];
  }
  m--;
  printf("%lld\n", m);
  return 0;
}
