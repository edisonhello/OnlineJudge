#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
const double eps = 0.000001;
int T, w, h, n;
struct Meteor { double x, y, a, b; } m[maxn];
struct Event { double x; int tp; };
vector<Event> ev;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T; while (T--) {
    cin >> w >> h;
    cin >> n;
    ev.clear();
    for (int i = 0; i < n; ++i) cin >> m[i].x >> m[i].y >> m[i].a >> m[i].b;
    for (int i = 0; i < n; ++i) {
      double L = 0.0, R = INT_MAX;
      if (m[i].a == 0) {
        if (m[i].x <= 0 || m[i].x >= w) R = L - 1;
      } else if (m[i].a > 0) {
        L = max(L, -m[i].x / m[i].a);
        R = min(R, (w - m[i].x) / m[i].a);
      } else {
        L = max(L, (w - m[i].x) / m[i].a);
        R = min(R, -m[i].x / m[i].a);
      }
      if (m[i].b == 0) {
        if (m[i].y <= 0 || m[i].y >= h) R = L - 1;
      } else if (m[i].b > 0) {
        L = max(L, -m[i].y / m[i].b);
        R = min(R, (h - m[i].y) / m[i].b);
      } else {
        L = max(L, (h - m[i].y) / m[i].b);
        R = min(R, -m[i].y / m[i].b);
      }
      if (R > L) ev.push_back((Event){ L + eps, 1 }), ev.push_back((Event){ R - eps, -1 });
    }
    sort(ev.begin(), ev.end(), [](const Event& a, const Event& b) -> bool {
      return a.x == b.x ? a.tp < b.tp : a.x < b.x;
    });
    int cur = 0, Max = 0;
    for (Event e : ev) {
      cur += e.tp;
      Max = max(Max, cur);
    }
    cout << Max << '\n';
  }
  return 0;
}
