#include <bits/stdc++.h>
#define int long long
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

const int maxn = 4000 + 5, maxk = 800 + 5;
const int INF = (1 << 30);
int n, k, u, S[maxn][maxn], dp[maxn][maxk], h[maxn][maxk];

inline int getSum(int, int);

signed main() {
  rit(n, k);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      rit(u), S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + u;
    }
  }
  memset(dp, 0x7f, sizeof(dp));
  for (int i = 1; i < maxk; ++i) h[i][i + 1] = i;
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = k; j >= 1; --j) {
      if (j == k) h[i][j + 1] = i - 1;
      for (int m = h[i - 1][j]; m <= h[i][j + 1]; ++m) {
        if (dp[m][j - 1] + getSum(m + 1, i) / 2 < dp[i][j]) {
          dp[i][j] = dp[m][j - 1] + getSum(m + 1, i) / 2;
          h[i][j] = m;
        }
      }
    }
  }
  printf("%lld\n", dp[n][k]);
  return 0;
}

inline int getSum(int L, int R) {
  return S[R][R] - S[L - 1][R] - S[R][L - 1] + S[L - 1][L - 1];
}
