#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int dp[1005][1005], f[1005][1005], g[1005][1005], N, A[1005], pre[1005];

int main() {
  // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
  cin >> N;
  for (int i = 1; i <= N; ++i) cin >> A[i], dp[i][i] = g[i][i] = f[i][i] = A[i], pre[i] = pre[i - 1] + A[i];
  for (int i = 1; i < N; ++i) {
    for (int j = 1; i + j <= N; ++j) {
      int m = 0;
      m = min({ m, f[j + 1][i + j], g[j][i + j - 1] });
      dp[j][i + j] = pre[i + j] - pre[j - 1] - m;
      f[j][i + j] = min(dp[j][i + j], f[j + 1][i + j]);
      g[j][i + j] = min(dp[j][i + j], g[j][i + j - 1]);
    }
  }
  cout << 2 * dp[1][N] - pre[N] << endl;
  return 0;
}
