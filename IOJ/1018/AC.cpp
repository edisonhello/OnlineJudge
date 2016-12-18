#include <iostream>
#include <set>
#include <algorithm>
#include <fstream>
using namespace std;

struct Point {
  int x, y;
  bool operator<(const Point& res) const {
    return x == res.x ? y < res.y : x < res.x;
  }
};

multiset<Point> S;
multiset<Point>::iterator it;
int N, x, y, T, kase;

int main() {
  // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
  cin >> N;
  S.clear();
  while (N--) {
    cin >> x >> y;
    Point p = (Point){ x, y };
    it = S.lower_bound(p);
    if (it == S.begin() || (--it)->y > p.y) {
      S.insert(p);
      it = S.upper_bound(p);
      while (it != S.end() && it->y >= p.y) S.erase(it++);
    }
    cout << S.size() << '\n';
  }
  return 0;
}
