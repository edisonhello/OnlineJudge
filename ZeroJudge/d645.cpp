#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;

struct Jizz {
  int v, w, t;
};

int main() {
  int dp[1010];
  Jizz jizz[1010];
  int cnt = 0;
  memset(dp, 0, sizeof(dp));
  int n, c, v, w, t;
  cin >> n >> c;
  for (int i = 0; i < n; ++i) {
    cin >> jizz[i].v >> jizz[i].w >> jizz[i].t;
  }
  for (int i = 0; i < n; ++i) {
    if (jizz[i].t == -1) jizz[i].t = INF;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = c; j >= jizz[i].w; --j) {
      int m = 0;
      for (int k = 1; k <= jizz[i].t; ++k) {
        if (j - jizz[i].w * k >= 0) m = max(m, dp[j - jizz[i].w * k] + jizz[i].v * k);
        else break;
      }
      if (m > dp[j])
        dp[j] = m;
    }
  }
  cout << dp[c] << endl;
  return 0;
}
