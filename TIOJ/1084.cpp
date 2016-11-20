#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
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

vector<pair<int, int>> G[505];
bool v[1050], odd;
int M, __i, __j, mn, cnt, leave[1050], start, oddN;
void DFS(int);

int main() {
  while (rit(M), M) {
    memset(v, false, sizeof(v));
    for (int i = 0; i < 505; ++i) G[i].clear();
    for (int i = 0; i < M; ++i) {
      rit(__i, __j);
      G[__i].push_back({ __j, i });
      G[__j].push_back({ __i, i });
    }
    for (int i = 1; i < 505; ++i) sort(G[i].begin(), G[i].end());
    start = 505; odd = false; oddN = 505;
    for (int i = 1; i < 505; ++i) {
      if (G[i].size() & 1) odd = true, oddN = min(oddN, i);
      else start = min(start, i);
    }
    if (odd) start = oddN;
    cnt = 0;
    DFS(start);
    for (int i = cnt - 1; i >= 0; --i) printf("%d\n", leave[i]);
    printf("\n");
  }
  return 0;
}

void DFS(int x) {
  for (auto i : G[x]) {
    if (!v[i.second]) {
      v[i.second] = true;
      DFS(i.first);
    }
  }
  leave[cnt++] = x;
}
