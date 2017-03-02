#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000 + 5;
int n;
long long dp[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  dp[0] = 1ll;
  for (int i = 1; i <= 21; ++i) {
    for (int j = 10000; j >= 0; --j) {
      for (int k = 1; j - k * i * i * i >= 0; ++k) dp[j] += dp[j - k * i * i * i];
    }
  }
  while (cin >> n) cout << dp[n] << '\n';
  return 0;
}
