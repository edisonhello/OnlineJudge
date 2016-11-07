#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n, dp[15][15];
bool v[15][15];
string mp[15];

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> mp[i];
  dp[0][0] = 0; v[0][0] = true;
  memset(v, true, sizeof(v));
  for (int i = 1; i < n; ++i) (mp[0][i] >= '0' && mp[0][i] <= '9') ? (dp[0][i] = mp[0][i] - '0' + dp[0][i - 1], v[0][i] = v[0][i - 1]) : (dp[0][i] = 0, v[0][i] = false);
  for (int i = 1; i < n; ++i) {
    (mp[i][0] >= '0' && mp[i][0] <= '9') ? (dp[i][0] = mp[i][0] - '0' + dp[i - 1][0], v[i][0] = v[i - 1][0]) : (dp[i][0] = 0, v[i][0] = false);
    for (int j = 1; j < n; ++j) {
      (mp[i][j] >= '0' && mp[i][j] <= '9') ? (dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + mp[i][j] - '0', v[i][j] = v[i - 1][j] || v[i][j - 1]) : (dp[i][j] = 0, v[i][j] = false);
    }
  }
  if (!(v[n - 1][n - 2] || v[n - 2][n - 1])) cout << 'X' << endl;
  else cout << max(dp[n - 2][n - 1], dp[n - 1][n - 2]) << endl;
  return 0;
}
