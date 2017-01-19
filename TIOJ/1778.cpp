#include <cstdio>
#define getchar getchar_unlocked
using namespace std;

char __c;
bool flag;

template <typename T>
inline bool rit(T& x) {
  __c = 0; flag = 0;
  while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
  (__c == '-') ? (x = 0, flag = true) : (x = __c - '0');
  while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
  if (flag) x = -x;
  return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

const int maxn = 100 + 5, MOD = 1000000009;
int N, M, S, T, a, b;
long long K, mat[maxn][maxn], tmp[maxn][maxn], A[maxn][maxn];

int main() {
  rit(N, M, S, T, K);
  while (M--) {
    rit(a, b);
    mat[a][b]++;
    mat[b][a]++;
  }
  for (int i = 1; i <= N; ++i) A[i][i] = 1;
  for (; K; K >>= 1) {
    if (K & 1) {
      for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) tmp[i][j] = A[i][j], A[i][j] = 0;
      for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
          for (int k = 1; k <= N; ++k) {
            A[i][j] += tmp[i][k] * mat[k][j];
            A[i][j] %= MOD;
          }
        }
      }
    }
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) tmp[i][j] = mat[i][j], mat[i][j] = 0;
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        for (int k = 1; k <= N; ++k) {
          mat[i][j] += tmp[i][k] * tmp[k][j];
          mat[i][j] %= MOD;
        }
      }
    }
  }
  printf("%lld\n", A[S][T] % MOD);
  return 0;
}
