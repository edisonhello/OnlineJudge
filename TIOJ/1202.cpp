#include <bits/stdc++.h>
using namespace std;

struct Event {
  int x, h, type;
  bool operator<(const Event& e) const {
    return x == e.x ? h == e.h ? type < e.type : h < e.h : x < e.x;
  }
};

vector<Event> v;
multiset<int, greater<int>> ms;
int N, L, H, R;


int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  while (cin >> N, N) {
    v.clear(); ms.clear();
    for (int i = 0; i < N; ++i) {
      cin >> L >> H >> R;
      v.push_back((Event){ L, H, 1 });
      v.push_back((Event){ R, H, 2 });
    }
    sort(v.begin(), v.end());
    int now = 0;
    ms.insert(0);
    for (int i = 0; i < v.size();) {
      int ii = i;
      while (ii < v.size() && v[ii].x == v[i].x) {
        if (v[ii].type == 1) ms.insert(v[ii].h);
        else ms.erase(ms.find(v[ii].h));
        ii++;
      }
      if (*ms.begin() != now) { now = *ms.begin(), cout << v[i].x << ' ' << now << ' '; }
      i = ii;
    }
    cout << '\n';
  }
  return 0;
}
