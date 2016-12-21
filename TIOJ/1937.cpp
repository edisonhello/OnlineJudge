#include <cstdio>
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

const int maxn = 1024;
int A[maxn][maxn], B[maxn][maxn], C[maxn][maxn], N, T, ans[maxn][maxn];
bool loli;

int main() {
  while (rit(N)) {
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) rit(A[i][j]);
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) rit(B[i][j]);
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        for (int k = 0; k < N; ++k) {
          ans[i][j] += A[i][k] * B[k][j];
        }
      }
    }
    loli = true;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) printf("%d ", ans[i][j]);
      puts("");
    }
  }
  return 0;
}
