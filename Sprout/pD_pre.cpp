#include <iostream>
#include <string>
using namespace std;

string s[2];
int cnt[2][26];

int main() {
  cin >> s[0] >> s[1];
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < s[i].length(); ++j) cnt[i][s[i][j] - 'a']++;
  }
  for (int i = 0; i < 26; ++i) if (cnt[0][i] != cnt[1][i]) { cout << "No\n"; return 0; }
  cout << "Yes\n";
  return 0;
}
