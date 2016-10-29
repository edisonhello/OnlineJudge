#include <iostream>
#include <set>
#include <cmath>
using namespace std;

const double INF = (1 << 30);

struct Point {
  double x, y;
};

struct Line {
  Point p1, p2;
  double m, b;
};

int n, cnt, ans;
Line l[105];

bool operator==(const Point& a, const Point& b) {
  return fabs(a.x - b.x) < 0.00000001 && fabs(a.y - b.y) < 0.00000001;
}

bool operator<(const Point& a, const Point& b) {
  return a.x == b.x ? a.y < b.y : a.x < b.x;
}

Point jizz(const Line& l1, const Line& l2) {
  if (l1.m == l2.m) return {INF, INF};
  if (l1.m == INF) {
    double x = l1.p1.x;
    double y = l2.m * x + l2.b;
    return {x, y};
  } else if (l2.m == INF) {
    double x = l2.p1.x;
    double y = l1.m * x + l1.b;
    return {x, y};
  }
  double x = (l2.b - l1.b) / (l1.m - l2.m);
  double y = l1.m * x + l1.b;
  return {x, y};
}

set<Point> st;

int main() {
  while (cin >> n, n) {
    ans = 1;
    for (int i = 0; i < n; ++i) {
      st.clear();
      // cout << "ans: " << ans << endl;
      cin >> l[i].p1.x >> l[i].p1.y >> l[i].p2.x >> l[i].p2.y;
      if (l[i].p1.x == l[i].p2.x) l[i].m = INF;
      else l[i].m = (l[i].p1.y - l[i].p2.y) / (l[i].p1.x - l[i].p2.x);
      l[i].b = l[i].p1.y - l[i].m * l[i].p1.x;
      cnt = 0;
      for (int j = i - 1; j >= 0; --j) {
        // cout << jizz(l[i], l[j]).x << ' ' << jizz(l[i], l[j]).y << endl;
        if (jizz(l[i], l[j]).x == INF || jizz(l[i], l[j]).y == INF) continue;
        if (st.find(jizz(l[i], l[j])) == st.end()) {
          st.insert(jizz(l[i], l[j]));
          cnt++;
        }
      }
      ans += 1 + cnt;
    }
    cout << ans << endl;
  }
  return 0;
}
