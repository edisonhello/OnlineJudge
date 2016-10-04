#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

long long int dp[810][810];
long long int p[810], n, jizz[810];
long long int dpdp(int, int);

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {cin >> p[i]; jizz[i] = (i == 0 ? p[i] : jizz[i - 1] + p[i]);}
  cout << dpdp(0, n - 1) - jizz[n - 1] << endl;
  return 0;
}

long long int dpdp(int l, int r) {
  if (l == r) return p[l];
  if (dp[l][r]) return dp[l][r];
  dp[l][r] = 1ll << 60;
  for (int k = l; k < r; ++k) {
    dp[l][r] = min(dp[l][r], dpdp(l, k) + dpdp(k + 1, r) + jizz[r] - jizz[l - 1]);
  }
  return dp[l][r];
}
