#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
using namespace std;

struct Point {
  double x, y;
  Point operator-(const Point& p) {
    return {x - p.x, y - p.y};
  }
  double operator*(const Point& p) {
    return x * p.y - y * p.x;
  }
};

int N, n, pos, neg;
string s;
stringstream ss;
Point p[11];
Point pp;
Point tmp;

int main() {
  while(getline(cin, s)) {
          //cout << s << endl;
    ss.clear();
    ss << s;
    n = 0;
    pos = 0; neg = 0;
    while (ss >> p[n++].x >> p[n].y);
    //scanf("%lf %lf\n", &pp.x, &pp.y);
    ss.clear();
    getline(cin, s);
    ss << s;
    ss >> pp.x >> pp.y;
    //cin >> pp.x >> pp.y; scanf("\n");
    p[n] = p[0];
    for (int i = 0; i < n; ++i) {
      tmp = p[i] - p[i + 1];
      if (pp * tmp > 0) pos++;
      else neg++;
    }
    if (pos > neg) cout << "Stop\n";
    else cout << "Hit him\n";
  }
  return 0;
}
