#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#define getchar getchar_unlocked
using namespace std;

char __c;
bool flag;

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
  int ed, l;
};

const int maxn = 100000 + 5, log = 20;
vector<Edge> T[maxn];
int N, Q, a, b, l, depth[maxn], fa[maxn], G[maxn], size[maxn], Min, num[maxn], t, x;
long long dist[log][maxn], sum[maxn], sum2[maxn];
bool d[maxn], v[maxn];
void CenterDecompose(int, int, int);
int center(int);
void DFS(int, int, long long, int);
void modify(int, int, int, int);
long long query(int, int, int, int);

int main() {
  rit(N, Q);
  for (int i = 0; i < N - 1; ++i) {
    rit(a, b, l);
    T[a].push_back((Edge){ b, l });
    T[b].push_back((Edge){ a, l });
  }
  memset(depth, -1, sizeof(depth));
  CenterDecompose(0, -1, 0);
  while (Q--) {
    rit(t, x);
    if (t == 1 && !d[x]) d[x] = true, modify(x, x, -1, depth[x]);
    if (t == 2) printf("%lld\n", query(x, x, -1, depth[x]));
  }
  return 0;
}

void CenterDecompose(int x, int g, int dep) {
  x = center(x); G[x] = g;
  depth[x] = dep;
  DFS(x, -1, 0, dep);
  for (auto u : T[x]) if (depth[u.ed] == -1) CenterDecompose(u.ed, x, dep + 1);
}

int center(int x) {
  static int q[maxn];
  int sz = 0;
  q[sz++] = x; fa[x] = -1;
  for (int i = 0; i < sz; ++i) for (auto u : T[q[i]]) {
    if (u.ed != fa[q[i]] && depth[u.ed] == -1) {
      fa[u.ed] = q[i]; q[sz++] = u.ed;
    }
  }
  int ret = -1, Max; Min = maxn;
  for (int i = sz - 1; i >= 0; --i) {
    int tmp = q[i]; size[tmp] = 1; Max = 0;
    for (auto u : T[tmp]) if (u.ed != fa[tmp] && depth[u.ed] == -1) {
      size[tmp] += size[u.ed]; Max = max(Max, size[u.ed]);
    }
    Max = max(Max, sz - size[tmp]);
    if (Max < Min) Min = Max, ret = tmp;
  }
  return ret;
}

void DFS(int x, int fa, long long dis, int dep) {
  dist[dep][x] = dis;
  for (auto u : T[x]) if (u.ed != fa && depth[u.ed] == -1) {
    DFS(u.ed, x, dis + u.l, dep);
  }
}

void modify(int x, int cent, int child, int dep) {
  if (cent == -1) return;
  num[cent]++;
  if (child == -1) { modify(x, G[cent], cent, dep - 1); return; }
  sum[cent] += dist[dep][x];
  sum2[child] += dist[dep][x];
  modify(x, G[cent], cent, dep - 1);
}

long long query(int x, int cent, int child, int dep) {
  if (cent == -1) return 0;
  long long ret = child == -1 ? sum[cent] : (num[cent] - num[child]) * dist[dep][x] + sum[cent] - sum2[child];
  return ret + query(x, G[cent], cent, dep - 1);
}
