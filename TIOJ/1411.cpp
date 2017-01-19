#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1000000 + 5;
int dp[maxn << 1], n, a, sum, Max;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  while (cin >> n) {
    memset(dp, -1, sizeof(dp));
    sum = 0; Max = 0;
    dp[maxn] = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> a;
      sum += (a == 0 ? 0 : a / abs(a));
      if (dp[sum + maxn] == -1) dp[sum + maxn] = i;
      else Max = max(Max, i - dp[sum + maxn]);
    }
    cout << Max << '\n';
  }
  return 0;
}
