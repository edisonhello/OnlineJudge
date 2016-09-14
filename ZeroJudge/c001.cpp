#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int LCS[1001][1001];

int main() {
  string s1, s2;
  while (getline(cin, s1)) {
    getline(cin, s2);
    memset(LCS, 0, sizeof(LCS));
    for (int i = 0; i < s1.length(); ++i) {
      for (int j = 0; j < s2.length(); ++j) {
        if (s1[i] == s2[j]) LCS[i + 1][j + 1] = LCS[i][j] + 1;
        else LCS[i + 1][j + 1] = max(LCS[i][j + 1], LCS[i + 1][j]);
      }
    }
    cout << LCS[s1.length()][s2.length()] << endl;
  }
  return 0;
}
