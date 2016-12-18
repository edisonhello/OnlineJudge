#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point {
  int x, y;
  bool operator<(const Point& rhs) const {
    return x == rhs.x ? y < rhs.y : x < rhs.x;
  }
} p[1005];

int N, dis, Min, ans;
const int INF = 1e9;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> N; Min = INF;
  for (int i = 0; i < N; ++i) cin >> p[i].x >> p[i].y;
  sort(p, p + N);
  for (int i = 0; i < N; ++i) {
    dis = 0;
    for (int j = 0; j < N; ++j) {
      if (i == j) continue;
      dis += abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y);
    }
    if (dis < Min) Min = dis, ans = i;
  }
  cout << p[ans].x << ' ' << p[ans].y << '\n' << Min << '\n';
  return 0;
}
