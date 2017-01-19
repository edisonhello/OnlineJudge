#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <climits>
#define getchar gtx
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

const int maxn = 100000 + 5, lg = 17;
int N, Q, djs[maxn], a, b, dep[maxn], p[lg][maxn], par[lg][maxn], node;
vector<int> G[maxn];

int F(int);
bool U(int, int);
void DFS(int, int, int);
int LCA(int, int);

int main() {
  rit(N, Q);
  for (int i = 1; i <= N; ++i) djs[i] = i;
  node = N;
  for (int i = N / 2; i >= 1; --i) {
    if (node == 1) break;
    for (int j = 2; i * j <= N; ++j) {
      if (!U(i * j, i * (j - 1))) continue;
      G[i * j].push_back(i * (j - 1));
      G[i * (j - 1)].push_back(i * j);
      if (node == 1) break;
    }
  }
  DFS(1, -1, 0);
  while (Q--) {
    rit(a, b);
    printf("%d\n", LCA(a, b));
  }
}

int F(int x) { return x == djs[x] ? x : djs[x] = F(djs[x]); }

void DFS(int x, int fa, int depth) {
  dep[x] = depth;
  p[0][x] = fa;
  par[0][x] = (fa == -1) ? INT_MAX : abs(x - fa);
  int prv = fa;
  for (int k = 1; k < lg; ++k) {
    if ((1 << k) > dep[x]) continue;
    p[k][x] = p[k - 1][p[k - 1][x]];
    par[k][x] = min(par[k - 1][x], par[k - 1][p[k - 1][x]]);
  }
  for (auto e : G[x]) if (e != fa) {
    DFS(e, x, depth + 1);
  }
}

int LCA(int a, int b) {
  int ret = INT_MAX;
  if (dep[a] > dep[b]) swap(a, b);
  for (int k = 0; k < lg; ++k) {
    if ((dep[b] - dep[a]) >> k & 1) ret = min(ret, par[k][b]), b = p[k][b];
  }
  for (int k = lg - 1; k >= 0; --k) {
    if (p[k][a] != p[k][b]) {
      ret = min({ ret, par[k][a], par[k][b] });
      a = p[k][a];
      b = p[k][b];
    }
    if (a == b) return ret;
  }
  ret = min({ ret, par[0][a], par[0][b] });
  return ret;
}

bool U(int a, int b) {
  a = F(a), b = F(b);
  if (a == b) return false;
  djs[a] = b;
  node--;
  return true;
}
