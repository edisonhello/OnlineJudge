#include <iostream>
#include <cstring>
#define INF 1 << 15
#define getchar getchar_unlocked
using namespace std;

int dp[510][510], n, m, __t, __i, __j, mn;
int w[510][510];
char __c;

inline int rit() {
  __t = 0;
  do {
    __c = getchar();
  } while (__c < '0' || __c > '9');
  do {
    __t = __t * 10 + __c - '0';
    __c = getchar();
  } while (__c >= '0' && __c <= '9');
  return __t;
}

int main() {
  while (cin >> n >> m) {
    // cin >> n >> m;
    if (n == 0 && m == 0) break;
    for (int i = 0; i <= n; ++i) for (int j = 0; j <= n; ++j) w[i][j] = INF;
    for (int i = 0; i < m; ++i) {
      __i = rit(), __j = rit();
      w[__i][__j] = 1;
    }
    mn = INF;
    memcpy(dp, w, sizeof(w));
    for (int i = 0; i <= n; ++i) dp[i][i] = INF;
    for (int k = 1; k <= n; ++k) {
      for (int i = 1; i < k; ++i) {
        for (int j = 1; j < k; ++j) {
          if (i != j) {
            if (mn > dp[i][j] + w[j][k] + w[k][i]) mn = dp[i][j] + w[j][k] + w[k][i];
          }
        }
        for (int i = 1; i <= n; ++i) {
          for (int j = 1; j <= n; ++j) {
            if (dp[i][k] + dp[k][j] < dp[i][j]) dp[i][j] = dp[i][k] + dp[k][j];
          }
        }
      }
    }
    if (mn == INF) cout << "0" << endl;
    else cout << mn << endl;
  }
  return 0;
}
