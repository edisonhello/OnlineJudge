#include <cstdio>
#include <vector>
#include <bitset>
#include <utility>
#define pii pair<int, int>
#define getchar getchar_unlocked
using namespace std;

int n, a, b, c, mx, mxi, __t, __k, i;
char __c;
vector<pii> G[100010];
bitset<100010> v;
void DFS(int, int);

inline int rit() {
  __t = 0; __k = 1;
  do {
    __c = getchar();
    if (__c == '-') __k = -1;
  } while (__c < '0' || __c > '9');
  do {
    __t = __t * 10 + __c - '0';
    __c = getchar();
  } while (__c >= '0' && __c <= '9');
  return __t * __k;
}

int main() {
  while (n = rit(), n) {
    for (i = 0; i < 100010; ++i) G[i].clear();
    v.reset();
    for (i = 0; i < n - 1; ++i) {
      a = rit(), b = rit(), c = rit();
      G[a].push_back(make_pair(b, c));
      G[b].push_back(make_pair(a, c));
    }
    mx = 0;
    v[1] = true;
    DFS(1, 0);
    mx = 0;
    v.reset();
    v[mxi] = true;
    DFS(mxi, 0);
    printf("%d\n", mx);
  }
  return 0;
}

void DFS(int start, int cnt) {
  if (cnt > mx) mx = cnt, mxi = start;
  for (int __i = 0; __i < G[start].size(); ++__i) {
    if (!v[G[start][__i].first]) {
      v[G[start][__i].first] = true;
      DFS(G[start][__i].first, cnt + G[start][__i].second);
    }
  }
}
