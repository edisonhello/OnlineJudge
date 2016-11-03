#include "lib1481.h"
#include <cstdio>
#include <vector>
#include <utility>
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

int n, k, st, ed, num[20005], cnt;
vector<pair<int, int>> G[2005];
bool v[20005];
void DFS(int);

int main() {
  Init();
  rit(n, k);
  for (int i = 1; i <= k; ++i) {
    rit(st, ed);
    G[st].push_back({ ed, i });
    G[ed].push_back({ st, i });
  }
  cnt = 1;
  DFS(1);
  Possible();
  for (int i = 1; i <= k; ++i) Number(num[i]);
  Finish();
  return 0;
}

void DFS(int x) {
  for (auto i : G[x]) {
    if (!v[i.second]) {
      v[i.second] = true;
      num[i.second] = cnt++;
      DFS(i.first);
    }
  }
}
