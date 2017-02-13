#include <bits/stdc++.h>
using namespace std;

const int maxn = 750 + 5;
int T, N;
long long dp[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T;
  while (T--) {
    cin >> N;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= N; i += 2) {
      for (int j = i; j <= N; ++j) dp[j] += dp[j - i];
    }
    cout << dp[N] << '\n';
  }
  return 0;
}
