#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
using namespace std;

struct Point {
  double x, y;
  Point operator-(const Point& p) const {
    return {x - p.x, y - p.y};
  }
  double operator*(const Point& p) const {
    return x * p.y - y * p.x;
  }
};

int id, neg, pos;
Point p[10], f;
string s;
stringstream ss;

int main() {
  while (getline(cin, s)) {
    ss.clear();
    ss << s;
    id = 0;
    while (ss >> p[id].x >> p[id].y) id++;
    scanf("%lf %lf\n", &f.x, &f.y);
    p[id] = p[0];
    pos = neg = 0;
    for (int i = 0; i < id; ++i) {
      if ((p[i] - f) * (p[i] - p[i + 1]) > 0) pos++;
      else neg++;
    }
    if (pos && neg) cout << "Stop\n";
    else cout << "Hit him\n";
  }
  return 0;
}
