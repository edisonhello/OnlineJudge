#include <iostream>
#include <cstring>
using namespace std;

int n, a11, scalar;
int mp[21][21], dp[21][21], m, lm, s[21], value;
void generate();
void solve();

int main() {
  while (cin >> n >> a11) {
    mp[1][1] = a11;
    generate();
    memset(dp, 0, sizeof(dp));
    m = 0;
    solve();
    cout << m << endl;
  }
}

void generate() {
  for (int i = 2; i <= n; ++i) mp[i][1] = a11 + i;
  for (int i = 1; i <= n; ++i) {
    for (int j = 2; j <= n; ++j) {
      if ((i + j) % 2) scalar = -1;
      else scalar = 1;
      mp[i][j] = ((mp[i][j - 1] * 17) % 103) * scalar;
    }
  }
}

void solve() {
  for (int i = 1; i <= n; ++i) {
    dp[1][i] = mp[1][i];
    for (int j = 2; j <= n; ++j) {
      dp[j][i] = dp[j - 1][i] + mp[j][i];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      memset(s, 0, sizeof(s));
      lm = 1;
      s[1] = dp[j][1] - (i == 1 ? 0 : dp[i - 1][1]);
      for (int k = 2; k <= n; ++k) {
        value = dp[j][k] - (i == 1 ? 0 : dp[i - 1][k]);
        if (s[k - 1] > 0) s[k] = s[k - 1] + value;
        else s[k] = value;
        if (s[k] > s[lm]) lm = k;
      }
      if (s[lm] > m) m = s[lm];
    }
  }
}
