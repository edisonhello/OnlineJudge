#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[100000], t, k, N, A[100000];
char c;

inline int rit() {
  t = 0, k = 1;
  do {
    c = getchar_unlocked();
    if (c == '-') k = -1;
  } while (c < '0' || c > '9');
  do {
    t = t * 10 + c - '0';
    c = getchar_unlocked();
  } while (c >= '0' && c <= '9');
  return t * k;
}

int main() {
  N = rit();
  for (int i = 0; i < N; ++i) {A[i] = rit(); dp[i] = 1;}
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (A[i] < A[j]) {
        dp[j] = max(dp[j], dp[i] + 1);
      }
    }
  }
  printf("%d\n", dp[N - 1]);
  return 0;
}
