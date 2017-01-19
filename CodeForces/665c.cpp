#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 5;
string s, t;
int dp[maxn];

char distinct(char, char);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> s;
  // t = s;
  for (int i = 1; i < s.length(); ++i) {
    if (s[i] == s[i - 1]) {
      if (i == 1) {
        dp[i] = dp[i - 1] + 1, s[i] = distinct(s[i - 1], s[i + 1]);
        continue;
      }
      if (dp[i - 1] < dp[i - 2]) dp[i] = dp[i - 1] + 1, t[i] = distinct(s[i - 1], s[i + 1]);
      else dp[i] = dp[i - 2] + 1, s[i - 1] = distinct(s[i - 2], s[i]);
    }
    else dp[i] = min(dp[i - 1], dp[i - 2]);
    // cout << "dp[i] = " << dp[i] << '\n';
  }
  cout << s << '\n';
  return 0;
}

char distinct(char c1, char c2) {
  char ret = 'a';
  while (ret == c1 || ret == c2) ret++;
  return ret;
}
