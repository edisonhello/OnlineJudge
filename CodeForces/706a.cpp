#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Point {
public:
  double x, y;
  Point() {}
  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }

  int dis(const Point& p) const {
    return sqrt((this->x - p.x) * (this->x - p.x) + (this->y - p.y) * (this->y - p.y));
  }
};

int main() {
  Point point[1000];
  double speed[1000];
  Point house;
  double a, b, v;
  cin >> a >> b;
  house = Point(a, b);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b >> v;
    point[i] = Point(a, b);
    speed[i] = v;
  }
  double min = 200000000;
  for (int i = 0; i < n; ++i) {
    if (house.dis(point[i]) / speed[i] < min) {
      min = house.dis(point[i]) / speed[i];
    }
  }
  cout << fixed << setprecision(20) << min << endl;
  return 0;
}
