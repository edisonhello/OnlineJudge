#include <iostream>
#include <vector>
#include <algorithm>
#define MAX (50000 + 5)
using namespace std;

struct Node {
  int deg, id, val;
  bool operator<(const Node& res) const {
    return deg > res.deg;
  }
} node[MAX];

int T, N, E, u, v, mx, deg[MAX];
vector<int> G[MAX];

int main() {
  // cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> N >> E; mx = 0;
    for (int i = 0; i < N; ++i) G[i].clear();
    for (int i = 0; i < N; ++i) node[i].id = i, node[i].val = -1;
    while (E--) {
      cin >> u >> v;
      if (u > v) deg[v]++;
      if (v > u) deg[u]++;
      node[u].deg++;
      node[v].deg++;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    for (int i = 0; i < N; ++i) mx = max(mx, deg[i]);
    cout << mx << ' ';
    mx = 0;
    sort(node, node + N);
    // for (int i = 0; i < N; ++i) cout << "node: " << node[i].id << ' ' << node[i].deg << '\n';
    for (int i = N - 1; i >= 0; --i) {
      node[i].val = i;
      int ret = 0;
      for (int s : G[node[i].id]) if (node[s].val > i) ret++;
      mx = max(mx, ret);
    }
    cout << mx << '\n';
  }
  return 0;
}
