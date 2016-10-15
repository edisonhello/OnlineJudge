#include <iostream>
#include <algorithm>
using namespace std;

int n, x[101], dp[10010], cnt[10010], s;

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> x[i];
  cin >> s;
  for (int i = 0; i < n; ++i) dp[x[i]] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = s; j >= x[i]; --j) {
      if (dp[j - x[i]]) {
        cnt[j]++;
        dp[j] = max(dp[j], dp[j - x[i]] + 1);
      }
    }
  }
  cout << dp[s] << ' ' << cnt[s] << endl;
  return 0;
}
