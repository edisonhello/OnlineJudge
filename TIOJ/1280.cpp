#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point {
  double x, y;
  double operator*(const Point& p) const {
    return x * p.y - y * p.x;
  }
  Point operator-(const Point& p) const {
    return {x - p.x, y - p.y};
  }
};

double cross(const Point& o, const Point& a, const Point& b) {
  return (a - o).x * (b - o).y - (a - o).y * (b - o).x;
}

Point p[10005], ch[10005];
int n, m;
double area;

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;
  sort(p, p + n, [](const Point& a, const Point& b) -> bool { return a.x == b.x ? a.y < b.y : a.x < b.x; });
  m = 0;
  for (int i = 0; i < n; ++i) {
    while (m >= 2 && cross(ch[m - 2], ch[m - 1], p[i]) <= 0) m--;
    ch[m++] = p[i];
  }
  for (int i = n - 2, t = m + 1; i >= 0; --i) {
    while (m >= t && cross(ch[m - 2], ch[m - 1], p[i]) <= 0) m--;
    ch[m++] = p[i];
  }
  m--;
  // cout << "m: " << m << endl;
  // for (int i = 0; i < m; ++i) cout << ch[i].x << ' ' << ch[i].y << endl;
  ch[m] = ch[0];
  area = 0.0;
  for (int i = 0; i < m; ++i) {
    // cout << fabs(ch[i] * ch[i + 1]) << endl;
    area += (ch[i] * ch[i + 1]);
  }
  printf("%.0lf\n", round(fabs(area) / 2));
  return 0;
}
