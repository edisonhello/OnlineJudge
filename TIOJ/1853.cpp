#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000000 + 5;
int dp[2][2], n, cur;
string s;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    dp[0][cur] = min(dp[0][cur ^ 1] + (s[i] == '1'), dp[1][cur ^ 1] + (s[i] == '1') + 1);
    dp[1][cur] = min(dp[1][cur ^ 1] + (s[i] == '0'), dp[0][cur ^ 1] + (s[i] == '0') + 1);
    cur ^= 1;
  }
  cout << min(dp[1][cur ^ 1], dp[0][cur ^ 1] + 1) << '\n';
  return 0;
}
