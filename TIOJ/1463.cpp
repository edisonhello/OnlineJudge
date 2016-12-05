#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int dp[10005];
string s;

int main() {
  while (cin >> s, s != "0") {
    memset(dp, 0, sizeof(dp));
    if (s[0] == '0') dp[0] = 0;
    else dp[0] = 1;
    if (s[1] == '0') dp[1] = dp[0];
    else dp[1] = dp[0] + 1;
    for (int i = 2; i < s.length(); ++i) {
      if (s[i] == '0') {
        if (s[i - 1] == '0') dp[i] = 0;
        else if (s[i - 1] <= '2') dp[i] = dp[i - 1];
        else dp[i] = 0;
      } else if (s[i] > '6') {
        if (s[i - 1] > '2') dp[i] = dp[i - 1];
        else if (s[i - 1] == '0') dp[i] = dp[i - 1];
        else dp[i] = dp[i - 1] + dp[i - 2];
      } else {
        if (s[i - 1] == '0') dp[i] = dp[i - 1];
        else dp[i] = dp[i - 1] + dp[i - 2];
      }
    }
    // for (int i = 0; i < s.length(); ++i) {
    //   cout << "dp[" << i << "]: " << dp[i] << endl;
    // }
    cout << dp[s.length() - 1] << endl;
  }
  return 0;
}
