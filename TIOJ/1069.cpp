#include <iostream>
#include <algorithm>
using namespace std;

struct Magic {
  int x, y, t;
  bool v;
  Magic(int x, int y, int t, bool v): x(x), y(y), t(t), v(v) {}
  Magic() {}
  bool operator < (const Magic& m) const {
    return t < m.t;
  }
};

int n, m, x, y, t, cnt;
Magic mg[1010];
bool p;

int dis(const Magic& m1, const Magic& m2) {
  return abs(m1.x - m2.x) + abs(m1.y - m2.y);
}

int main() {
  cin >> n;
  while (n--) {
    cin >> m;
    for (int i = 0; i < m; ++i) {
      cin >> t >> x >> y;
      mg[i] = Magic(x, y, t, false);
    }
    sort(mg, mg + m);
    cnt = 0;
    for (int i = 0; i < m; ++i) {
      p = false;
      for (int j = 0; j < i; ++j) {
        if (mg[j].t + dis(mg[i], mg[j]) <= mg[i].t && mg[j].v) {mg[j].v = false; mg[i].v = true; p = true; break;}
      }
      if (!p) {cnt++; mg[i].v = true;}
    }
    cout << cnt << endl;
  }
}
