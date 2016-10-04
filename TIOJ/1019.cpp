#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int n, len, i, j;
long long int dp[1000], dis[1000], t;
char c;

inline long long int rit() {
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
  n = rit();
  for (i = 0; i < n; ++i) {
    len = rit();
    for (j = 0; j < len; ++j) {
      dis[j] = rit();
    }
    dp[0] = 0;
    dp[1] = abs(dis[1] - dis[0]);
    for (j = 2; j < len; ++j) {
      dp[j] = min(dp[j - 1] + abs(dis[j] - dis[j - 1]), dp[j - 2] + abs(dis[j] - dis[j - 2]));
    }
    printf("%lld\n", dp[len - 1]);
  }
  return 0;
}
