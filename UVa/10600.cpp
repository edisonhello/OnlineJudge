#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
struct Edge { int from, to, cost; };
vector<Edge> edge, G[maxn];
int T, N, M, djs[maxn], fa[10][maxn], Max[10][maxn], d[maxn], Min;
bool tree[maxn * maxn];

int F(int x) { return x == djs[x] ? x : djs[x] = F(djs[x]); }
void dfs(int, int, int, int);
int LCA(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T; while (T--) {
    edge.clear();
    cin >> N >> M;
    for (int i = 0; i < maxn; ++i) djs[i] = i;
    for (int i = 0; i < maxn; ++i) G[i].clear();
    memset(tree, false, sizeof(tree));
    memset(fa, 0, sizeof(fa));
    memset(Max, 0, sizeof(Max));
    for (int i = 0; i < M; ++i) {
      int a, b, c; cin >> a >> b >> c;
      edge.push_back((Edge){ a, b, c });
    }
    sort(edge.begin(), edge.end(), [](const Edge& a, const Edge& b) -> bool {
      return a.cost < b.cost;
    });
    int now = 1, mst = 0;
    for (int i = 0; i < edge.size(); ++i) {
      Edge e = edge[i];
      int a = F(e.from), b = F(e.to);
      if (a == b) continue;
      ++now; mst += e.cost;
      djs[a] = b;
      G[a].push_back((Edge){ a, b, e.cost });
      G[b].push_back((Edge){ b, a, e.cost });
      tree[i] = true;
      if (now == N) break;
    }
    dfs(F(1), 0, 0, 0);
    cout << mst << ' ';
    Min = INT_MAX;
    for (int i = 0; i < edge.size(); ++i) {
      Edge e = edge[i];
      if (tree[i]) continue;
      Min = min(Min, mst - LCA(e.from, e.to) + e.cost);
    }
    cout << Min << '\n';
  }
  return 0;
}

void dfs(int x, int p, int w, int dep) {
  fa[0][x] = p;
  Max[0][x] = w;
  d[x] = dep;
  for (int i = 1; i < 10; ++i) {
    if ((1 << i) > dep) break;
    fa[i][x] = fa[i - 1][fa[i - 1][x]];
    Max[i][x] = max(Max[i - 1][x], Max[i - 1][fa[i - 1][x]]);
  }
  for (Edge e : G[x]) if (e.to != p) {
    dfs(e.to, x, e.cost, dep + 1);
  }
}

int LCA(int a, int b) {
  int ret = 0;
  if (d[a] > d[b]) swap(a, b);
  for (int i = 0; i < 10; ++i) {
    if ((d[b] - d[a]) >> i & 1) {
      ret = max(ret, Max[i][b]);
      b = fa[i][b];
    }
  }
  if (a == b) return ret;
  for (int i = 9; i >= 0; --i) {
    if (fa[i][a] != fa[i][b]) {
      ret = max({ ret, Max[i][a], Max[i][b] });
      a = fa[i][a];
      b = fa[i][b];
    }
    if (a == b) return ret;
  }
  ret = max({ ret, Max[0][a], Max[0][b] });
  return ret;
}
