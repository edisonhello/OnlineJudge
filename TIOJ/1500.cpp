#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define INF 7074000997ll
#define eps (1e-7)
using namespace std;

struct Point {
  double x, y;
};

Point p[50005];
int N;
double mn;

double dis(const Point& a, const Point& b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
  while (cin >> N) {
    for (int i = 0; i < N; ++i) cin >> p[i].x >> p[i].y;
    auto cmp = [](const Point& a, const Point& b) -> bool {
      return a.x < b.x;
    };
    sort(p, p + N, cmp);
    mn = INF;
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
          if (p[i].x + mn < p[j].x + eps) break;
          if (dis(p[i], p[j]) < mn + eps) mn = dis(p[i], p[j]);
      }
    }
    cout << fixed << setprecision(6) << mn << endl;
  }
  return 0;
}
