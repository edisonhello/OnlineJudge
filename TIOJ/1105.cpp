#include <iostream>
#include <algorithm>
#include <cmath>
#define INF (int)(1e9)
using namespace std;

struct Point {
  double x, y;
  Point(double x, double y): x(x), y(y) {}
  Point() {}
};

int n, l, u, i1, i2;
double mx;
Point p[3005];
Point L[3005], U[3005];
double x, y;

int main() {
  while (cin >> n, n) {
    mx = 0.;
    for (int i = 0; i < n; ++i) {
      cin >> x >> y;
      p[i] = Point(x, y);
      for (int j = i - 1; j >= 0; --j) {
        if (dis(p[i], p[j]) > mx) {
          mx = dis(p[i], p[j]);
          i1 = j, i2 = i;
        } else if (dis(p[i], p[j]) == mx) {
          if (j < i1) i1 = j, i2 = i;
          else if (j == i1 && i < i2) i1 = j, i2 = i;
        }
      }
    }
    cout << i1 << ' ' << i2 << endl;
  }
  return 0;
}
