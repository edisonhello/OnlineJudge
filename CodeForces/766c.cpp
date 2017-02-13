#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1000 + 5, MOD = 1000000007, sigma = 26;
int n, a[sigma], sum[sigma][maxn], dp[3][maxn];
string s, t;

bool valid(int, int);

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> s;
  t = "*";
  for (int i = 0; i < n; ++i) t += s[i];
  s = t;
  for (int i = 0; i < n; ++i) cin >> a[i];
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    dp[0][i] = dp[0][i - 1]; dp[1][i] = max(1LL, dp[1][i - 1]); dp[2][i] = dp[2][i - 1] + 1;
    for (int j = 1; j < i; ++j) {
      if (valid(j, i)) {
        dp[1][i] = max(dp[1][i], i - j + 1);
        dp[0][i] = (dp[0][i] + dp[0][j - 1]) % MOD;
        dp[2][i] = min(dp[2][i], dp[2][j - 1] + 1);
      }
    }
  }
  cout << dp[0][n] << '\n' << dp[1][n] << '\n' << dp[2][n] << '\n';
  return 0;
}

bool valid(int L, int R) {
  for (int i = L; i <= R; ++i) {
    if (R - L + 1 > a[s[i] - 'a']) return false;
  }
  return true;
}
