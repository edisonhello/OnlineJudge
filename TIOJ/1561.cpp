#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
struct Edge { int from, to, cost; };
int n, m, d[2][maxn], s, t;
vector<Edge> G[maxn];

struct Heap {
  int id, d;
  bool operator>(const Heap& rhs) const {
    return d > rhs.d;
  }
};

priority_queue<Heap, vector<Heap>, greater<Heap>> pq;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> n >> m) {
    for (int i = 0; i < maxn; ++i) G[i].clear();
    while (m--) {
      int a, b, w; cin >> a >> b >> w;
      G[a].push_back((Edge){ a, b, w });
      G[b].push_back((Edge){ b, a, w });
    }
    cin >> s >> t;
    fill(d[0], d[0] + maxn, 100000000);
    fill(d[1], d[1] + maxn, 100000000);
    d[0][s] = 0;
    pq.push((Heap){ s, 0 });
    while (pq.size()) {
      Heap tmp = pq.top(); pq.pop();
      for (Edge e : G[tmp.id]) {
        int dis = e.cost + tmp.d;
        if (dis < d[0][e.to]) {
          swap(dis, d[0][e.to]);
          pq.push((Heap){ e.to, d[0][e.to] });
        }
        if (dis < d[1][e.to] && dis > d[0][e.to]) {
          swap(dis, d[1][e.to]);
          pq.push((Heap){ e.to, d[1][e.to] });
        }
      }
    }
    if (d[1][t] == 100000000) d[1][t] = -1;
    cout << d[1][t] << '\n';
  }
  return 0;
}
