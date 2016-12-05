#include <cstdio>
#include <vector>
#include <cstring>
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

int N, K, R, C, match[1005], ans, c;
vector<int> G[1005];
bool v[1005];
bool DFS(int);

int main() {
  while (rit(N, K), (N || K)) {
    for (int i = 1; i <= N; ++i) G[i].clear();
    while (K--) {
      rit(R, C);
      G[R].push_back(C);
    }
    ans = 0;
    memset(match, 0, sizeof(match));
    for (int i = 1; i <= N; ++i) {
      memset(v, false, sizeof(v));
      if (DFS(i)) ans++;
    }
    printf("Case #%d:%d\n", ++c, ans);
  }
  return 0;
}

bool DFS(int x) {
  v[x] = true;
  for (auto i : G[x]) {
    if (!match[i] || !v[match[i]] && DFS(match[i])) {
      match[i] = x;
      return true;
    }
  }
  return false;
}
