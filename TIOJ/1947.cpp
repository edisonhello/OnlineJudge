#include <cstdio>
#include <algorithm>
#include <vector>
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

const int maxn = 1000000 + 5;
vector<int> G[maxn];
int N, a, b, dp[2][maxn], Min;

int DP(int, int);

int main() {
  rit(N);
  for (int i = 0; i < N - 1; ++i) rit(a, b), G[a].push_back(b), G[b].push_back(a);
  DP(0, -1);
  Min = INT_MAX;
  for (int i = 0; i < N; ++i) Min = min(Min, max(dp[0][i], N - dp[1][i]));
  printf("%d\n", Min);
  return 0;
}

int DP(int x, int fa) {
  dp[1][x] = 1;
  for (int u : G[x]) if (u != fa) {
    int d = DP(u, x);
    dp[1][x] += d;
    dp[0][x] = max(dp[0][x], d);
  }
  return dp[1][x];
}
