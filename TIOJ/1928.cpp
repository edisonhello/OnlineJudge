#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct Point {
  int x, y;
  Point operator-(const Point& res) const {
    return (Point){ x - res.x, y - res.y };
  }
} p[805];

const double INF = 10000000000.0;
int N, mx, my, tran[805][805];
double dpa[805][805];
double dis(const Point&, const Point&);
double dp(int, int);
void answer(int, int);

int main() {
  // cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> p[i].x >> p[i].y;
    mx += p[i].x; my += p[i].y;
  }
  mx /= N; my /= N;
  sort(p, p + N, [](const Point& a, const Point& b) -> bool {
    Point p1 = a - (Point){ mx, my }, p2 = b - (Point){ mx, my };
    return atan(p1.y / p1.x) < atan(p2.y / p2.x);
  });
  dp(0, N - 1);
  answer(0, N - 1);
  return 0;
}

double dp(int L, int R) {
  if (L + 1 == R) return 0;
  double ret = INF;
  for (int k = L + 1; k < R; ++k) {
    int d = dp(L, k) + dp(k, R) + dis(p[L], p[R]);
    if (d < ret) {
      ret = d;
      tran[L][R] = k;
    }
  }
  return dpa[L][R] = ret;
}

double dis(const Point& a, const Point& b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void answer(int L, int R) {
  if (L + 1 == R) return;
  cout << L << ' ' << R << '\n';
  answer(L, tran[L][R]);
  answer(tran[L][R], R);
}
