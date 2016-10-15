#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[10010], T, W, B, N, A[1010], D[1010], M, m, k, t;
char c;

inline int rit() {
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
  T = rit();
  while (T--) {
    W = rit(); B = rit(); N = rit();
    for (int i = 0; i < N; ++i) A[i] = rit(), D[i] = rit();
    M = rit();
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; ++i) {
      for (int j = A[i]; j <= W; ++j) {
        if (j - A[i] - M > 0) dp[j] = max(dp[j], dp[j - A[i] - M] + D[i]);
      }
    }
    if (dp[W] < B) printf("No\n");
    else printf("Yes\n");
  }
  return 0;
}
