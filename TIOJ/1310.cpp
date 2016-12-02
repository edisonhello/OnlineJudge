#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct Point {
  double x, y;
  bool operator<(const Point& p) const {
    return x == p.x ? y < p.y : x < p.x;
  }
} p[100005];

double dis(const Point& a, const Point& b) {
  return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int N;
double ans;

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> p[i].x >> p[i].y;
  sort(p, p + N);
  for (int i = 0; i < N - 1; ++i) ans += dis(p[i], p[i + 1]);
  cout << fixed << setprecision(2) << ans << endl;
  return 0;
}
