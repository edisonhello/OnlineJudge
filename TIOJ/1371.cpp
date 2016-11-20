#include <iostream>
#include <algorithm>
using namespace std;

struct Point {
  int x, y;
} p[100005], ch[100005];

int n;

int cross(const Point& o, const Point& a, const Point& b) {
  return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;
  sort(p, p + n, [](const Point& a, const Point& b) -> bool {
    return a.x == b.x ? a.y < b.y : a.x < b.x;
  });
  m = 0;
  for (int i = 0; i < n; ++i) {
    if (m >= 2 && cross(ch[m - 2], ch[m - 1], p[i]) <= 0) m--;
    ch[m++] = p[i];
  }
  for (int i = n - 2, t = m + 1; i >= 0; --i) {
    while (m >= t && cross(ch[m - 2], ch[m - 1], p[i]) <= 0) m--;
    ch[m++] = p[i];
  }
  m--;
  ch[m] = ch[0];
  
}
