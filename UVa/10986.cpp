#include <iostream>
#include <queue>
#include <cstring>
#include <deque>
#include <string>
#include <cstdio>
using namespace std;

#define INF 1000000

struct Edge {
  int from, to;
  int w;
  bool operator<(const Edge& e) const {
    return e.w < w;
  }
};

deque<Edge> G[50000];
bool v[20000];
int dis[20000];

int main() {
  int N, n, m, S, T, a, b, w;
  priority_queue<Edge> pq;
  Edge tmp, pqEdge;

  cin >> N;
  for (int k = 0; k < N; ++k) {
    cin >> n >> m >> S >> T;
    for (int i = 0; i < n; ++i) {
      G[i].clear();
    }
    for (int i = 0; i < m; ++i) {
      cin >> a >> b >> w;
      tmp.from = a;
      tmp.to = b;
      tmp.w = w;
      G[a].push_back(tmp);
      tmp.from = b;
      tmp.to = a;
      tmp.w = w;
      G[b].push_back(tmp);
    }

    memset(v, false, sizeof(v));
    memset(dis, INF, sizeof(dis));

    pqEdge.from = S;
    pqEdge.w = 0;
    dis[S] = 0;
    pq.push(pqEdge);

    while (!pq.empty()) {
      pqEdge = pq.top();
      pq.pop();
      int from = pqEdge.from;

      if (!v[from]) {
        v[from] = true;
        for (int i = 0; i < G[from].size(); ++i) {
          if (dis[G[from][i].to] > dis[from] + G[from][i].w) {
            dis[G[from][i].to] = dis[from] + G[from][i].w;
            tmp.from = G[from][i].to;
            tmp.w = dis[from] + G[from][i].w;
            pq.push(tmp);
          }
        }
      }
    }
    if (dis[T] >= INF) {
      printf("Case #%d: %s\n", k + 1, "unreachable");
    } else {
      printf("Case #%d: %d\n", k + 1, dis[T]);
    }
  }
  return 0;
}
