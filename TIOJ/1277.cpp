#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

long long int dp[510][510];
long long int power[510][510];
long long int m;
long long int s[510];
int main() {
  long long int n;
  cin >> n;
  for (long long int i = 0; i < n; ++i) for (long long int j = 0; j < n; ++j) cin >> power[i][j];
  memset(dp, 0, sizeof(dp));
  for (long long int i = 0; i <= n; ++i) {
    dp[0][i] = power[0][i];
    for (long long int j = 1; j <= n; ++j) {
      dp[j][i] = dp[j - 1][i] + power[j][i];
    }
  }
  long long int value; long long int lm;
  m = 0;
  for (long long int i = 0; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      memset(s, 0, sizeof(s));
      lm = 0;
      s[0] = dp[j][0] - (i == 0 ? 0 : dp[i - 1][0]);
      for (long long int k = 1; k <= n; ++k) {
        value = dp[j][k] - (i == 0 ? 0 : dp[i - 1][k]);
        if (s[k - 1] > 0) {
            s[k] = s[k - 1] + value;
        } else {
            s[k] = value;
        }
        if (s[k] > s[lm]) lm = k;
      }
      if (s[lm] > m) {
        m = s[lm];
      }
    }
  }
  cout << m << endl;
  return 0;
}
