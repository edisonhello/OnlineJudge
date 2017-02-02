#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
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
  int to, cost;
};

const int maxn = 100000 + 5;
vector<Edge> G[maxn];
int N, M, L, dfs, rad, Long, Longg, Longgg, ans, a, b, c, bound;
Edge go[maxn];
bool v[maxn];

Edge DFS(int, int);

int main() {
  while (rit(N, M, L)) {
    for (int i = 0; i < maxn; ++i) G[i].clear();
    for (int i = 0; i < M; ++i) {
      rit(a, b, c);
      G[a].push_back((Edge){ b, c });
      G[b].push_back((Edge){ a, c });
    }
    dfs = 0; ans = 0; Long = Longg = Longgg = 0;
    memset(v, false, sizeof(v));
    for (int i = 0; i < N; ++i) if (!v[i]) {
      bound = DFS(i, -1).to;
      rad = DFS(bound, -1).cost;
      ans = max(ans, rad);
      int r = 0, now = bound;
      if (rad) while (r + go[now].cost <= rad / 2) {
        r += go[now].cost;
        now = go[now].to;
      }
      int half = min(r + go[now].cost, rad - r);
      if (half > Long) Longgg = Longg, Longg = Long, Long = half;
      else if (half > Longg) Longgg = Longg, Longg = half;
      else if (half > Longgg) Longgg = half;
    }
    if (N - M > 2) ans = max({ ans, Long + Longg + L, Longg + L * 2 + Longgg });
    else if (N - M > 1) ans = max(ans, Long + Longg + L);
    printf("%d\n", ans);
  }
  return 0;
}

Edge DFS(int x, int fa) {
  Edge ret = (Edge){ x, 0 };
  go[x] = ret;
  v[x] = true;
  for (Edge e : G[x]) if (e.to != fa) {
    Edge ee = DFS(e.to, x);
    ee.cost += e.cost;
    if (ee.cost > ret.cost) ret = ee, go[x] = e;
  }
  return ret;
}
