#include <vector>
#include <iostream>
#include <string>
using namespace std;

vector<int> G[30];
int in[30];
string s;
char key;
bool v[26]; bool one;
int pos1, pos2, len1, len2, idx, ii;
char grid[2][13];

int main() {
  cin >> s;
  for (int i = 0; i < s.length(); ++i) {
    if (!v[s[i] - 'A']) v[s[i] - 'A'] = true;
    else { key = s[i]; break; }
  }
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == key && !one) pos1 = i, one = true;
    else if (s[i] == key && one) { pos2 = i; break; }
  }
  len1 = pos1, len2 = 26 - pos2;
  if (pos2 - pos1 == 1) { cout << "Impossible\n"; return 0; }
  if (len2 > len1) {
    for (idx = len2 - len1, ii = 0; ii < len1; ++idx, ++ii) grid[0][idx] = s[ii];
    for (idx--, ii = pos1; idx < 13; ++idx, ++ii) grid[1][idx] = s[ii];
    for (idx = 12; !grid[0][idx]; --idx, ++ii) grid[0][idx] = s[ii];
    for (++ii, idx = len1 - 1; idx >= 0; --idx, ++ii) grid[1][idx] = s[ii];
    for (idx = 0; idx < len2 - len1; ++idx, ++ii) grid[0][idx] = s[ii];
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 13; ++j) {
      if (grid[i][j]) cout << grid[i][j];
      else cout << '.';
    }
    cout << endl;
  }
  cout << endl;
}
