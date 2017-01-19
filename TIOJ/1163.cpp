#include <vector>
#include <cstdio>
#include <algorithm>
#define getchar getchar_unlocked
using namespace std;

char __c;
bool flag;

inline int gtx() {
  const int N = 1048576;
  static char buffer[N];
  static char *p = buffer, *end = buffer;
  if (p == end) {
    if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
    p = buffer;
  }
  return *p++;
}

template <typename T>
inline bool rit(T& x) {
  __c = 0, flag = false;
  while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
  __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
  while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
  if (flag) x = -x;
  return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

struct Edge {
  int from, to, cost;
  bool operator<(const Edge& e) const {
    return cost < e.cost;
  }
};

const int maxn = 30000 + 5, lg = 15;
vector<Edge> E, MST[maxn];
int N, M, a, b, c, djs[maxn], p[lg][maxn], dis[lg][maxn], Q, dep[maxn], id[maxn], dfs;

void Kruskal();
void DFS(int, int, int, int);
int LCA(int, int);
int F(int);

int main() {
  rit(N, M);
  for (int i = 1; i <= N; ++i) djs[i] = i;
  while (M--) {
    rit(a, b, c);
    E.push_back((Edge){ a, b, c });
  }
  Kruskal();
  for (int i = 1; i <= N; ++i) {
    if (!id[i]) ++dfs, DFS(i, 0, 0, 0);
  }
  rit(Q);
  while (Q--) {
    rit(a, b);
    printf("%d\n", LCA(a, b));
  }
  return 0;
}

void Kruskal() {
  int node = 1;
  sort(E.begin(), E.end());
  for (auto e : E) {
    if (node == N) return;
    int f = F(e.from), t = F(e.to);
    if (f == t) continue;
    MST[f].push_back((Edge){ f, t, e.cost });
    MST[t].push_back((Edge){ t, f, e.cost });
    djs[f] = t;
    node++;
  }
}

void DFS(int x, int fa, int depth, int cost) {
  dep[x] = depth;
  p[0][x] = fa;
  dis[0][x] = cost;
  id[x] = dfs;
  for (int k = 1; k < lg; ++k) {
    if ((1 << k) > dep[x]) continue;
    p[k][x] = p[k - 1][p[k - 1][x]];
    dis[k][x] = max(dis[k - 1][x], dis[k - 1][p[k - 1][x]]);
  }
  for (auto e : MST[x]) if (e.to != fa) {
    DFS(e.to, x, depth + 1, e.cost);
  }
}

int LCA(int a, int b) {
  if (id[a] != id[b]) return -1;
  int ret = 0;
  if (dep[a] > dep[b]) swap(a, b);
  for (int k = 0; k < lg; ++k) {
    if ((dep[b] - dep[a]) >> k & 1) ret = max(ret, dis[k][b]), b = p[k][b];
  }
  if (a == b) return ret;
  for (int k = lg - 1; k >= 0; --k) {
    if (p[k][a] != p[k][b]) {
      ret = max({ ret, dis[k][a], dis[k][b] });
      a = p[k][a];
      b = p[k][b];
    }
    if (a == b) return ret;
  }
  ret = max({ ret, dis[0][a], dis[0][b] });
  return ret;
}

int F(int x) { return x == djs[x] ? x : djs[x] = F(djs[x]); }
