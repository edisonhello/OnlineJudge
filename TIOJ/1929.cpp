#include <cstdio>
#include <vector>
#include <bitset>
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

vector<int> G[1000005], R[1000005];
vector<int> S;
int N, M, a, b, start, clk, sccno[1000005], scc_cnt;
bitset<1000005> v;
void DFS(int);
void dfs(int);

int main() {
  rit(N, M);
  while (M--) {
    rit(a, b);
    G[a].push_back(b);
    R[b].push_back(a);
  }
  for (int i = 1; i <= N; ++i) DFS(i);
  for (int i = N - 1; i >= 0; --i) {
    if (!sccno[S[i]]) {
      scc_cnt++;
      dfs(S[i]);
    }
  }
  printf("%d\n", scc_cnt);
  for (int i = 1; i <= N; ++i) printf("%d ", sccno[i]);
  return 0;
}

void DFS(int x) {
  if (v[x]) return;
  v[x] = true;
  for (int u : G[x]) DFS(u);
  S.push_back(x);
}

void dfs(int x) {
  if (sccno[x]) return;
  sccno[x] = scc_cnt;
  for (int u : R[x]) dfs(u);
}
