#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, dp[2000005][3], ans, tmp;
string s, jizz;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> N >> s;
  jizz = "CEP";
  do {
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for (int i = 0; i < N; ++i) {
      tmp = 0;
      for (int j = 0; j < 3; ++j) {
        tmp = max(tmp, dp[i][j]);
        dp[i + 1][j] = tmp + (s[i] == jizz[j] ? 1 : 0);
      }
    }
    ans = max(ans, dp[N][2]);
  } while (next_permutation(jizz.begin(), jizz.end()));
  cout << ans << '\n';
  return 0;
}
