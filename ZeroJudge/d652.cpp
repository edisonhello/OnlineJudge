#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

long long int dp[51][51];
int A[100];

// int f(int )
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> A[i];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
        if (j > i + 1) {
          long long int m = 1000000000;
          for (int k = i + 1; k < j; ++k) m = min(m, dp[i][k] + dp[k][j] + A[i] * A[j] * A[k]);
          dp[i][j] = m;
        } else {
          dp[i][j] = 0;
        }
    }
  }
  cout << dp[0][n - 1] << endl;
  return 0;
}
