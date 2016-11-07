#include <cstdio>
#include <vector>
#include <bitset>
#include <queue>
#define INF (1 << 30)
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

vector<int> G[1005];
int T, N, K, x, w[1005], tot;
Vertex v[1005];
void DFS(int, int);

int F(int x) { return x == djs[x] ? x : djs[x] = F(djs[x]); }

void U(int x, int y) {
  x = F(x); y = F(y);
  djs[x] = y;
}

struct Vertex {
  int in, w, id;
};

int main() {
  rit(T);
  while (T--) {
    rit(N);
    for (int i = 1; i <= N; ++i) G[i].clear();
    for (int i = 1; i <= N; ++i) {
      rit(v[i].w, K); v[i].id = i;
      for (int j = 0; j < K; ++j) rit(x), G[i].push_back(x), U(i, x);
    }
    for (int i = 1; i <= N; ++i) DFS(i, w[i]);
    for (int i = 1; i <= N; ++i) mx[F(i)] = max(mx[F(i)], mn[i]);
    tot = 0;
    for (int i = 1; i <= N; ++i) if (mx[i]) tot += mx[i];
    printf("%d\n", tot);
  }
  return 0;
}

void DFS(int x, int cur) {
  mn[x] = max(mn[x], cur);
  for (auto i : G[x]) DFS(i, cur + w[i]);
}
