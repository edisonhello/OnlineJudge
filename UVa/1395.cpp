#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
struct Edge { int a, b, w; };
vector<Edge> e;
int n, m;

struct Djs {
  int djs[maxn];
  void init() {
    for (int i = 0; i < maxn; ++i) djs[i] = i;
  }
  int F(int x) { return x == djs[x] ? x : djs[x] = F(djs[x]); }
} djs;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> n >> m, n || m) {
    e.clear();
    while (m--) {
      int a, b, w; cin >> a >> b >> w;
      e.push_back((Edge){ a, b, w });
    }
    sort(e.begin(), e.end(), [](const Edge& osas, const Edge& hao) {
      return osas.w < hao.w;
    });
    int ans = INT_MAX;
    for (int i = 0; i < e.size(); ++i) {
      djs.init();
      int Max = 0, vertex = 1;
      for (int j = i; j < e.size(); ++j) {
        int a = djs.F(e[j].a), b = djs.F(e[j].b);
        if (a == b) continue;
        djs.djs[a] = b;
        Max = max(Max, e[j].w - e[i].w);
        ++vertex;
      }
      if (vertex == n) ans = min(ans, Max);
    }
    if (ans == INT_MAX) ans = -1;
    cout << ans << '\n';
  }
  return 0;
}
