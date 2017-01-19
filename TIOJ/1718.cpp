#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 10000 + 5;
int dp[maxn], M, N, P, w[55][55], v[55][55];

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> M >> N >> P;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < P; ++j) cin >> w[i][j] >> v[i][j];
  }
  for (int i = 0; i < N; ++i) {
    for (int j = M; j >= 0; --j) {
      for (int k = 0; k < P; ++k) {
        if (j - w[i][k] >= 0) dp[j] = max(dp[j], dp[j - w[i][k]] + v[i][k]);
      }
    }
  }
  cout << dp[M] << '\n';
  return 0;
}
