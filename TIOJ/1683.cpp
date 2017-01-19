#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>
#define getchar getchar_unlocked
using namespace std;

char __c;
bool flag;

template <typename T>
inline bool rit(T& x) {
  __c = 0; flag = 0;
  while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
  (__c == '-') ? (x = 0, flag = true) : (x = __c - '0');
  while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
  if (flag) x = -x;
  return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

const int maxn = 10000 + 5;
vector<int> G[maxn], R[maxn], T[maxn];
vector<int> topo;
int N, M, t, a, b, scc, ans, dpa[maxn], SCC[maxn], sz[maxn];
bool v[maxn];

void DFS1(int);
void DFS2(int);
int dp(int);

int main() {
  rit(t);
  while (t--) {
    rit(N, M);
    for (int i = 1; i <= N; ++i) G[i].clear(), R[i].clear(), T[i].clear();
    while (M--) {
      rit(a, b);
      G[a].push_back(b);
      R[b].push_back(a);
    }
    memset(SCC, 0, sizeof(SCC));
    memset(v, false, sizeof(v));
    memset(sz, 0, sizeof(sz));
    while (topo.size()) topo.pop();
    for (int i = 1; i <= N; ++i) if (!v[i]) DFS1(i);
    memset(v, false, sizeof(v));
    scc = 0;
    while (topo.size()) {
      if (!v[topo.top()]) ++scc, DFS2(topo.top());
      topo.pop();
    }
    for (int i = 1; i <= N; ++i) for (int u : G[i]) if (SCC[i] != SCC[u]) T[SCC[i]].push_back(SCC[u]);
    for (int i = 1; i <= scc; ++i) {
      sort(T[i].begin(), T[i].end());
      T[i].resize(unique(T[i].begin(), T[i].end()) - T[i].begin());
    }
    ans = 0;
    memset(dpa, -1, sizeof(dpa));
    for (int i = 1; i <= scc; ++i) ans = max(ans, dp(i));
    printf("%d\n", ans);
  }
  return 0;
}

void DFS1(int x) {
  v[x] = true;
  for (int u : G[x]) if (!v[u]) DFS1(u);
  topo.push_back(x);
}

void DFS2(int x) {
  v[x] = true;
  SCC[x] = scc;
  sz[scc]++;
  for (int u : R[x]) if (!v[u]) DFS2(u);
}

int dp(int x) {
  if (dpa[x] != -1) return dpa[x];
  dpa[x] = sz[x];
  for (int u : T[x]) dpa[x] = max(dpa[x], sz[x] + dp(u));
  return dpa[x];
}
