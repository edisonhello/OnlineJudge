#include <cstdio>
#include <cstring>
#include <bitset>
#include <algorithm>
#include <iostream>
#define INF (1 << 30)
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
inline bool rit(T& x, Args& ...args) {return rit(x) && rit(args...);}

int T, N, R[21][21], dp[1 << 21];
int dpdp(int);

int main() {
  rit(T);
  while (T--) {
    rit(N);
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) rit(R[i][j]);
    memset(dp, 0, sizeof(dp));
    printf("%d\n", dpdp((1 << N) - 1));
  }
}

int dpdp(int nw) {
  if (nw == 0) return 0;
  if (dp[nw]) return dp[nw];
  int mn = INF;
  for (int i = 0; i < N; ++i) {
    if (nw & (1 << i)) {
      for (int j = i + 1; j < N; ++j) {
        if (nw & (1 << j)) {
          for (int k = j + 1; k < N; ++k) {
            if (nw & (1 << k)) {
              mn = min(mn, dpdp(nw ^ (1 << i) ^ (1 << j) ^ (1 << k)) + R[i][j] + R[j][k] + R[k][i]);
            }
          }
        }
      }
      break;
    }
  }
  return dp[nw] = mn;
}
