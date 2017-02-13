#include <bits/stdc++.h>
#define Lc(id) (id << 1)
#define Rc(id) (id << 1 | 1)
using namespace std;

struct Edge { int from, to, w; };

const int maxn = 10000 + 5;
int T, N, dep[maxn], fa[maxn], top[maxn], size[maxn], son[maxn], stamp[maxn], dfs, seg[maxn << 2];
vector<int> G[maxn];
Edge e[maxn];
string cmd;

void Init();
void DFS(int, int, int);
void HeavyLightDecompose(int, int);
void pull(int);
void modify(int, int, int, int, int);
int LCA(int, int);
int query(int, int, int, int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T;
  while (T--) {
    Init();
    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
      cin >> e[i].from >> e[i].to >> e[i].w;
      --e[i].from, --e[i].to;
      G[e[i].from].push_back(e[i].to);
      G[e[i].to].push_back(e[i].from);
    }
    DFS(0, -1, 0);
    HeavyLightDecompose(0, 0);
    for (int i = 0; i < N - 1; ++i) {
      if (dep[e[i].from] > dep[e[i].to]) swap(e[i].from, e[i].to);
      modify(1, 1, dfs, stamp[e[i].to], e[i].w);
    }
    while (cin >> cmd) {
      int a, b;
      if (cmd == "DONE") break;
      if (cmd == "CHANGE") cin >> a >> b, --a, modify(1, 1, dfs, stamp[e[a].to], b);
      if (cmd == "QUERY") cin >> a >> b, --a, --b, cout << LCA(a, b) << '\n';
    }
  }
  return 0;
}

void Init() {
  memset(seg, 0, sizeof(seg));
  memset(e, 0, sizeof(e));
  memset(stamp, 0, sizeof(stamp));
  memset(fa, -1, sizeof(fa));
  memset(son, -1, sizeof(son));
  memset(top, -1, sizeof(top));
  memset(size, 0, sizeof(size));
  memset(dep, -1, sizeof(dep));
  dfs = 0;
  for (int i = 0; i < maxn; ++i) G[i].clear();
}

void DFS(int x, int f, int depth) {
  fa[x] = f;
  size[x] = 1;
  dep[x] = depth;
  son[x] = -1;
  for (int i = 0; i < G[x].size(); ++i) if (G[x][i] != f) {
  	int u = G[x][i];
    DFS(u, x, depth + 1);
    size[x] += size[u];
    if (son[x] == -1 || size[u] > size[son[x]]) son[x] = u;
  }
}

void HeavyLightDecompose(int x, int tp) {
  stamp[x] = ++dfs;
  top[x] = tp;
  if (son[x] == -1) return;
  HeavyLightDecompose(son[x], tp);
  for (int i = 0; i < G[x].size(); ++i) if (G[x][i] != fa[x]) {
  	int u = G[x][i];
    if (u == son[x]) continue;
    HeavyLightDecompose(u, u);
  }
}

void pull(int id) {
  seg[id] = max(seg[Lc(id)], seg[Rc(id)]);
}

void modify(int id, int L, int R, int x, int v) {
  if (L == R) { seg[id] = v; return; }
  int M = (L + R) >> 1;
  if (x <= M) modify(Lc(id), L, M, x, v);
  else modify(Rc(id), M + 1, R, x, v);
  pull(id);
}

int LCA(int a, int b) {
  int ta = top[a], tb = top[b];
  int ret = 0;
  while (ta != tb) {
    if (dep[ta] < dep[tb]) swap(ta, tb), swap(a, b);
    ret = max(ret, query(1, 1, dfs, stamp[ta], stamp[a]));
    a = fa[ta], ta = top[a];
  }
  if (a == b) return ret;
  if (dep[a] > dep[b]) swap(a, b);
  return max(ret, query(1, 1, dfs, stamp[son[a]], stamp[b]));
}

int query(int id, int L, int R, int l, int r) {
  if (L > r || l > R) return 0;
  if (L >= l && R <= r) return seg[id];
  int M = (L + R) >> 1;
  int a = query(Lc(id), L, M, l, r), b = query(Rc(id), M + 1, R, l, r);
  return max(a, b);
}
