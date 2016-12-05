#include <iostream>
#include <algorithm>
using namespace std;

int N, T, C[100005], H[100005], *dp;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> N >> T; dp = new int[T + 5];
  for (int i = 0; i < N; ++i) cin >> C[i] >> H[i];
  for (int i = 0; i < N; ++i) {
    for (int j = T; j >= H[i]; --j) {
      if (j >= C[i]) dp[j] = max({ dp[j], dp[j - C[i]] + 2, dp[j - H[i]] + 1 });
      else dp[j] = max(dp[j], dp[j - H[i]] + 1);
    }
  }
  cout << dp[T] << endl;
  return 0;
}
