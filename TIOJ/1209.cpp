#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

vector<int> G[40010];
int color[40010], t, n, m, a, b, i;
char c;
bool v[40010];
void DFS(int);
bool suc;

inline bool rit(int& t) {
  t = 0;
  do {
    c = getchar_unlocked();
  } while (c < '0' || c > '9');
  do {
    t = t * 10 + c - '0';
    c = getchar_unlocked();
  } while (c >= '0' && c <= '9');
  return t;
}

int main() {
  while (rit(n)) {
    rit(m);
    if (n == 0 && m == 0) break;
    for (int i = 0; i <= n; ++i) G[i].clear();
    memset(v, 0, sizeof(v));
    memset(color, 0, sizeof(color));
    for (i = 0; i < m; ++i) {
      rit(a);
      rit(b);
      G[a].push_back(b);
      G[b].push_back(a);
    }
    suc = true;
    color[1] = 1;
    DFS(1);
    if (suc) {printf("Yes\n");}
  }
  return 0;
}

void DFS(int start) {
  for (int j = 0; j < G[start].size() && suc; ++j) {
    if (!v[G[start][j]]) {
      v[G[start][j]] = true;
      if (color[start] == 1) color[G[start][j]] = 2;
      else color[G[start][j]] = 1;
      DFS(G[start][j]);
    } else {
      if (color[G[start][j]] == color[start]) {printf("No\n"); suc = false; return;}
    }
  }
}
