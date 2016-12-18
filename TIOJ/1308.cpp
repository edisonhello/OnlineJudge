#include <iostream>
#include <cstring>
using namespace std;

long long dp[51][51];
int N, M;

long long C(int n, int k) {
  if (dp[n][k] != -1) return dp[n][k];
  if (n == k || k == 0) return 1;
  return dp[n][k] = C(n - 1, k - 1) + C(n - 1, k);
}

int main() {
  memset(dp, -1, sizeof(dp));
  while (cin >> N >> M, N) {
    cout << C(N + M - 1, M) << '\n';
  }
  return 0;
}
