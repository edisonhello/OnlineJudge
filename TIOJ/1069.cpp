#include <vector>
#include <cmath>
#include <cstring>
#include <bitset>
#include <cstdio>
using namespace std;

struct S {
  int t, x, y;
} s[1005];

char __c;
bool flag;
int n, m, match[1005], cnt;
vector<int> G[1005];
bool v[1005];
bool DFS(int);


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

int main() {
  rit(n);
  while (n--) {
    rit(m);
    for (int i = 0; i < m; ++i) rit(s[i].t, s[i].x, s[i].y), G[i].clear();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i == j) continue;
        if (abs(s[i].x - s[j].x) + abs(s[i].y - s[j].y) + s[i].t <= s[j].t) G[i].push_back(j);
      }
    }
    cnt = 0;
    memset(match, 0, sizeof(match));
    for (int i = 0; i < m; ++i) {
      DFS(i);
      memset(v, 0, sizeof(v));
    }
    printf("%d\n", m - cnt);
  }
  return 0;
}

bool DFS(int x) {
  v[x] = true;
  for (auto i : G[x]) {
    if (!v[match[i] - 1]) {
      if (!match[i] || DFS(match[i] - 1)) {
        if (!match[i]) cnt++;
        match[i] = x + 1;
        return true;
      }
    }
  }
  return false;
}
