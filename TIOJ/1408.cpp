#include <iostream>
#include <algorithm>
using namespace std;

struct W {
  int a, b, c;
  bool operator<(const W& w) const {
    return a == w.a ? b < w.b : a < w.a;
  }
};

W w[100005];
int n, sm, tot;

int main() {
  while (cin >> n, n) {
    sm = 0; tot = 0;
    for (int i = 0; i < n; ++i) cin >> w[i].a >> w[i].b >> w[i].c, tot += w[i].c;
    sort(w, w + n);
    for (int i = 0; i < n - 1; ++i) {
      if (w[i].b > w[i + 1].a) if (w[i].b - w[i + 1].a >= w[i + 1].c) sm += w[i].b - w[i + 1].a;
    }
    cout << tot - sm << endl;
  }
  return 0;
}
