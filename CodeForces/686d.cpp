#include <iostream>
#include <vector>
using namespace std;

const int maxn = 300000 + 5;
vector<int> T[maxn];
int n, q, u, depth[maxn], G[maxn],fa[maxn], size[maxn];

void CenterDecompose(int, int, int);
int center(int);

int main() {
  cin >> n >> q;
  for (int i = 2; i <= n; ++i) {
    cin >> u;
    T[i].push_back(u);
    T[u].push_back(i);
  }
  memset(depth, -1, sizeof(depth));
  CenterDecompose(1, 0, 0);
  while (q--) {
    int Q; cin >> Q;
    cout << G[Q] << '\n';
  }
  return 0;
}

void CenterDecompose(int x, int g, int dep) {
  // G[x] = center(x);
  cout << x << ' ';
  x = center(x);
  cout << x << '\n';
  depth[x] = dep;
  for (int u : T[x]) if (depth[u] == -1) CenterDecompose(u, x, dep + 1);
}

int center(int x) {
  static int q[maxn];
  int sz = 0;
  q[sz++] = x; fa[x] = 0;
  for (int i = 0; i < sz; ++i) for (int u : T[q[i]]) {
    if (u != fa[q[i]] && depth[u] == -1) {
      fa[u] = q[i]; q[sz++] = u;
    }
  }
  int ret = 0, Max, Min = maxn;
  for (int i = sz - 1; i >= 0; --i) {
    size[q[i]] = 1; Max = 0;
    for (int u : T[q[i]]) if (u != fa[q[i]] && depth[u] == -1) {
      size[q[i]] += size[u]; Max = max(Max, size[u]);
    }
    Max = max(Max, sz - size[q[i]]);
    if (Max < Min) Min = Max, ret = q[i];
  }
  return ret;
}
