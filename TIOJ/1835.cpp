#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, dp[1005][1005], mp[1005][1005];
string s1, s2, s3;
void solve(int, int);
vector<string> ans;

int main() {
  scanf("%d\n", &n);
  while (n--) {
    getline(cin, s1); getline(cin, s2);
    s3 = "";
    memset(dp, 0, sizeof(dp));
    memset(mp, 0, sizeof(mp));
    for (int i = 0; i < s1.length(); ++i) {
      for (int j = 0; j < s2.length(); ++j) {
        if (s1[i] == s2[j]) dp[i + 1][j + 1] = dp[i][j] + 1, mp[i + 1][j + 1] = 3;
        else {
          if (dp[i][j + 1] > dp[i + 1][j]) dp[i + 1][j + 1] = dp[i][j + 1], mp[i + 1][j + 1] = 1;
          else dp[i + 1][j + 1] = dp[i + 1][j], mp[i + 1][j + 1] = 2;
        }
      }
    }
    ans.clear();
    solve(s1.length(), s2.length());
    if (dp[s1.length()][s2.length()]) {
      sort(ans.begin(), ans.end());
      cout << ans[0] << endl;
    }
    else cout << "妹萌えこそ正義なのさ！" << endl;
  }
  return 0;
}

void solve(int x, int y) {
  if (x == 0 || y == 0) {ans.push_back(reverse(s3.begin(), s3.end())); return;}
  if (mp[x][y] == 3) s3 += s1[x - 1], solve(x - 1, y - 1);
  else if (mp[x][y] == 2) solve(x, y - 1);
  else solve(x - 1, y);
}
