#include <iostream>
#include <cmath>
#define INF (1 << 30)
using namespace std;

int n, t;
double px, py, x, y, vx, vy;
const double EPS = 0.00000001;
bool p;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  while (cin >> n >> t >> px >> py) {
    if (n == 0 && t == 0 && px == 0 && py == 0) break;
    p = false;
    for (int i = 0; i < n; ++i) {
      cin >> x >> y >> vx >> vy;
      if (!p) {
        if (px == x && py == y) { cout << "true\n"; p = true; }
        if (vx == 0) {
          if (x == px) {
            double tt = (y - py) / vy;
            if (abs(tt) <= t) { cout << "true\n"; p = true; }
          }
        } else if (vy == 0) {
          if (y == py) {
            double tt = (x - px) / vx;
            if (abs(tt) <= t) { cout << "true\n"; p = true; }
          }
        } else {
          double tt = (x - px) / vx;
          if (fabs(fabs(py + tt * vy) - y) < EPS) {
            if (abs(tt) <= t) { cout << "true\n"; p = true; }
          }
        }
      }
    }
    if (!p) cout << "false\n";
  }
  return 0;
}
