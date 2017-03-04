#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int T, n, m, kase;
struct Edge { int a, b, w; };
vector<Edge> e;

struct Djs {
  int djs[maxn];
  void init() {
    for (int i = 0; i < maxn; ++i) djs[i] = i;
  }
  int F(int x) { return x == djs[x] ? x : djs[x] = F(djs[x]); }
  void U(int a, int b) {
    a = F(a); b = F(b);
    djs[a] = b;
  }
} djs;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T; while (T--) {
    djs.init(); e.clear();
    cin >> n >> m;
    while (m--) {
      int a, b, w; cin >> a >> b >> w;
      e.push_back((Edge){ a, b, w });
    }
    sort(e.begin(), e.end(), [](const Edge& osas, const Edge& hao) {
      return osas.w < hao.w;
    });
    int vertex = 1, ans = 0;
    for (Edge ed : e) {
      int a = djs.F(ed.a), b = djs.F(ed.b);
      if (a == b) continue;
      ans += ed.w; ++vertex;
      djs.U(a, b);
    }
    cout << "Case #" << ++kase << ": ";
    if (vertex != n) cout << "Possums!\n";
    else cout << ans << '\n';
  }
  return 0;
}
