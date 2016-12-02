#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#define int long long
#define INF (1 << 30)
using namespace std;

struct Edge {
  int st, ed, slope;
  bool operator<(const Edge& e) const {
    return slope > e.slope;
  }
};

struct Node {
  int id, t;
  bool operator>(const Node& node) const {
    return t > node.t;
  }
};

vector<Edge> G[10005];
int T, N, M, S, h[10005], dis[10005], st, ed, walk, edd, mn, c, car, start, near[10005], cnt;
priority_queue<Node, vector<Node>, greater<Node>> pq;
queue<Node> q;
bool v[10005], can, done, keep;
Node tmp;
void DFS(int);

signed main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> N >> M >> S; mn = INF;
    for (int i = 0; i < N; ++i) {
      cin >> h[i];
      if (h[i] < mn) mn = h[i], edd = i;
    }
    for (int i = 0; i < N; ++i) G[i].clear();
    while (M--) {
      cin >> st >> ed;
      G[st].push_back((Edge){ st, ed, h[st] - h[ed] });
      G[ed].push_back((Edge){ ed, st, h[ed] - h[st] });
    }
    for (int i = 0; i < N; ++i) near[i] = -1;
    for (int i = 0; i < N; ++i) {
      sort(G[i].begin(), G[i].end());
      if (G[i].size() && G[i][0].slope > 0) near[i] = G[i][0].ed;
    }
    start = S; car = INF;
    while (h[start] != h[edd] && near[start] != -1) {
      start = near[start];
      cnt++;
      if (h[start] == h[edd]) car = cnt;
    }
    memset(v, false, sizeof(v));
    while (q.size()) q.pop();
    q.push((Node){ S, 0 });
    walk = INF;
    while (q.size()) {
      auto tmp = q.front(); q.pop();
      v[tmp.id] = true;
      if (h[tmp.id] == h[edd]) { walk = tmp.t; break; }
      for (auto i : G[tmp.id]) {
        if (!v[i.ed]) q.push((Node){ i.ed, tmp.t + 1 });
      }
    }
    if (walk < INF) walk *= 6;
    start = S; done = false; keep = true;
    ++c;
    if (walk == INF && car == INF) cout << "Case #" << c << ": Call 119!\n";
    else if (walk == INF) cout << "Case #" << c << ": " << car << '\n';
    else if (car == INF) cout << "Case #" << c << ": " << walk << '\n';
    else cout << "Case #" << c << ": " << abs(walk - car) << '\n';
  }
  return 0;
}
