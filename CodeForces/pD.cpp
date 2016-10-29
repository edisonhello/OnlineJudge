#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct Balloon {
  long long t, w;
  bool operator>(const Balloon& b) const {
    return w - t == b.w - b.t ? t > b.t : w - t > b.w - b.t;
  }
};

Balloon b;
Balloon Limak, tmp;
vector<Balloon> v;
int n, rnk;
priority_queue<Balloon, vector<Balloon>, greater<Balloon>> pq;

int main() {
  cin >> n;
  cin >> Limak.t >> Limak.w;
  for (int i = 1; i < n; ++i) cin >> b.t >> b.w, pq.push(b);
  // sort(b + 1, b + n, [](const Balloon& a, const Balloon& b) -> bool { return a.w - a.t == b.w - b.t ? a.t > b.t : a.w - a.t < b.w - b.t; });
  // while (pq.size()) {
  //   cout << pq.top().t << ' ' << pq.top().w << endl;
  //   pq.pop();
  // }
  while (Limak.t > 0) {
    tmp = pq.top(), pq.pop();
    if (tmp.t > Limak.t) {
      cout << tmp.t << ' ' << tmp.w << ' ' << Limak.t << ' ' << Limak.w << endl;
      if (Limak.t > tmp.w - tmp.t + 1) {
        Limak.t -= (tmp.w - tmp.t + 1);
        tmp.t = 0; tmp.w = 0;
        for (int i = 0; i < v.size(); ++i) pq.push(v[i]);
        v.clear();
      } else break;
    } else {
      v.push_back(tmp);
    }
    // pq.push(tmp);
  }
  rnk = 1;
  while (pq.top().t > Limak.t) {
    rnk++;
    pq.pop();
  }
  cout << rnk + 1 << endl;
  return 0;
}
