#include <iostream>
#include <deque>
using namespace std;

struct Edge {
  int from, to;
  int w;
};

deque<Edge> G[100000];
int store[10000];
int n, m, k;

int find(int num) {
  for (int i = 0; i < n; ++i) {
    if (store[i] == num) {
      return i;
    }
  }
  return -1;
}

int main() {
  int u, v, w;
  int s;
  Edge e;
  cin >> n >> m >> k;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> w;
    e.from = u;
    e.to = v;
    e.w = w;
    G[u].push_back(e);
    e.from = v;
    e.to = u;
    e.w = w;
    G[v].push_back(e);
  }
  int min = 20000000;
  for (int i = 0; i < k; ++i) {
    cin >> store[i];
  }
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < G[store[i]].size(); ++j) {
      if (find(G[store[i]][j].to) == -1) {
        if (G[store[i]][j].w < min) min = G[store[i]][j].w;
      }
    }
  }
  if (min >= 20000000) cout << -1 << endl;
  else  cout << min << endl;

  return 0;
}
