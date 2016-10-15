#include <iostream>
#include <string>
using namespace std;

string mp[101];
int n, cnt;

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> mp[i];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cnt = 0;
      if (mp[i][j] != '*') {
        if (i + 1 < n && mp[i + 1][j] == '*') cnt++;
        if (i - 1 >= 0 && mp[i - 1][j] == '*') cnt++;
        if (j + 1 < n && mp[i][j + 1] == '*') cnt++;
        if (j - 1 >= 0 && mp[i][j - 1] == '*') cnt++;
        if (i + 1 < n && j + 1 < n && mp[i + 1][j + 1] == '*') cnt++;
        if (i + 1 < n && j - 1 >= 0 && mp[i + 1][j - 1] == '*') cnt++;
        if (i - 1 >= 0 && j + 1 < n && mp[i - 1][j + 1] == '*') cnt++;
        if (i - 1 >= 0 && j - 1 >= 0 && mp[i - 1][j - 1] == '*') cnt++;
        if (cnt > 0) mp[i][j] = cnt + '0';
      }
    }
  }
  for (int i = 0; i < n; ++i) cout << mp[i] << endl;
  return 0;
}
