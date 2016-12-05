#include <cstdio>
#define getchar getchar_unlocked
using namespace std;

char __c;
bool flag;

template <typename T>
inline bool rit(T& x) {
  __c = 0; flag = false;
  while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
  __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
  while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
  if (flag) x = -x;
  return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) {return rit(x) && rit(args...);}

int N, M, K, X1, Y1, X2, Y2, step;
bool dp[10005][105][105];

int main() {
  rit(N, M);
  rit(X1, Y1, X2, Y2);
  rit(K);
  dp[0][X1][Y1] = 1;
  for (int i = 0; i < K; ++i) {
    rit(step);
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < M; ++k) {
        if (dp[i][j][k]) {
          dp[i + 1][(j + step) % N][k] = dp[i + 1][(j - step + 100 * N) % N][k] = dp[i + 1][j][(k + step) % M] = dp[i + 1][j][(k - step + 100 * M) % M] = 1;
        }
      }
    }
  }
  if (dp[K][X2][Y2]) printf("YES\n");
  else printf("NO\n");
  return 0;
}
