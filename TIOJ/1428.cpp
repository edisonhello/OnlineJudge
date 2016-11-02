#include <cstdio>
#define getchar getchar_unlocked
#define int long long
using namespace std;

const int M = 1000000009;

int n, m, Q, L, s, e, ans[150][150], a[150][150], tmp[150][150];
void power();
void mul1();
void mul2();

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

signed main() {
  rit(n, m, Q, L);
  for (int i = 0; i < m; ++i) {
    rit(s, e);
    a[s][e]++;
  }
  for (int i = 0; i < n; ++i) ans[i][i] = 1;
  power();
  for (int i = 0; i < Q; ++i) {
    rit(s, e);
    printf("%lld\n", ans[s][e] % M);
  }
  return 0;
}

void power() {
  int n = L;
  for (; n; n /= 2) {
    if (n & 1) mul1();
    mul2();
  }
}

void mul1() {
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) tmp[i][j] = ans[i][j];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ans[i][j] = 0;
      for (int k = 0; k < n; ++k) {
          ans[i][j] += a[i][k] * tmp[k][j];
          ans[i][j] %= M;
      }
    }
  }
}

void mul2() {
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) tmp[i][j] = a[i][j];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      a[i][j] = 0;
      for (int k = 0; k < n; ++k) {
          a[i][j] += tmp[i][k] * tmp[k][j];
          a[i][j] %= M;
      }
    }
  }
}
