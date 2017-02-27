#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000;

struct Event {
  int x, tp;
  bool operator<(const Event& e) const {
    return x == e.x ? tp < e.tp : x < e.x;
  }
};

int n, m;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> n >> m, n || m) {
    vector<Event> v;
    for (int i = 0; i < n; ++i) {
      int L, R; cin >> L >> R;
      v.push_back((Event){ L, 1 });
      v.push_back((Event){ R, -1 });
    }
    for (int i = 0; i < m; ++i) {
      int L, R, p; cin >> L >> R >> p;
      for (int j = 0; ; ++j) {
        if (L + j * p > MAX) break;
        v.push_back((Event){ L + j * p, 1 });
        v.push_back((Event){ R + j * p, -1 });
      }
    }
    sort(v.begin(), v.end());
    int cur = 0;
    bool ans = false;
    for (Event e : v) {
      if (ans) break;
      cur += e.tp;
      if (cur > 1) ans = true, cout << "CONFLICT\n";
    }
    if (!ans) cout << "NO CONFLICT\n";
  }
  return 0;
}
