#include <cstdio>
#include <vector>
#include <bitset>
#define lowbit(x) (x) & (-x)
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
  int id, ed, w;
  Edge(int id, int ed, int w): id(id), ed(ed), w(w) {}
};

const int maxn = 100000 + 5;
const int log = 20;
vector<Edge> T[maxn];
int depth[maxn << 1], vs[maxn << 1], st[log][maxn], in[maxn], BIT[maxn << 1], id[maxn << 1];
int N, Q, S, a[maxn], b[maxn], w[maxn], dfs, type;
bitset<maxn> v;
void DFS(int, int);
int LCA(int, int);
void add(int, int);
int query(int);

int main() {
  rit(N, Q, S); S--;
  for (int i = 0; i < N - 1; ++i) {
    rit(a[i], b[i], w[i]); a[i]--; b[i]--;
    T[a[i]].push_back(Edge(i, b[i], w[i]));
    T[b[i]].push_back(Edge(i, a[i], w[i]));
  }
  DFS(0, 0);
  for (int i = 0; i < 2 * N; ++i) st[0][i] = i;
  for (int i = 1; (1 << i) <= 2 * N; ++i) {
    for (int j = 0; j + (1 << i) <= 2 * N; ++j) {
      st[i][j] = depth[st[i - 1][j]] < depth[st[i - 1][j + (1 << (i - 1))]] ? st[i - 1][j] : st[i - 1][j + (1 << (i - 1))];
    }
  }
  while (Q--) {
    rit(type);
    if (!type) {
      int u; rit(u); u--;
      printf("%d\n", query(in[S]) + query(in[u]) - (query(in[LCA(S, u)]) << 1));
      S = u;
    } else {
      int i, nw; rit(i, nw);
      i--;
      add(id[(i << 1)], nw - w[i]);
      add(id[(i << 1) + 1], w[i] - nw);
      w[i] = nw;
    }
  }
  return 0;
}

void DFS(int x, int dep) {
  v[x] = true;
  in[x] = dfs;
  vs[dfs] = x;
  depth[dfs++] = dep;
  for (int i = 0; i < T[x].size(); ++i) if (!v[T[x][i].ed]) {
    id[T[x][i].id << 1] = dfs;
    add(dfs, T[x][i].w);
    DFS(T[x][i].ed, dep + 1);
    vs[dfs] = x;
    depth[dfs++] = dep;
    id[(T[x][i].id << 1) + 1] = dfs;
    add(dfs, -T[x][i].w);
  }
}

int LCA(int a, int b) {
  a = in[a]; b = in[b];
  if (a > b) swap(a, b);
  int p = 31 - __builtin_clz(b - a + 1);
  return depth[st[p][a]] < depth[st[p][b - (1 << p) + 1]] ? vs[st[p][a]] : vs[st[p][b - (1 << p) + 1]];
}

void add(int x, int w) {
  while (x <= (N - 1) * 2) {
    BIT[x] += w;
    x += lowbit(x);
  }
}

int query(int x) {
  int ret = 0;
  while (x) ret += BIT[x], x -= lowbit(x);
  return ret;
}
