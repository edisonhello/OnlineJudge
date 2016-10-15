#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;

string s;

int main() {
  while (cin >> s) {
    for (int i = s.length() - 1; i >= 0; --i) {
      if (s[i] != '.' && s[i] != '-') {
        if (s[i - 2] != '.' && s[i - 1] != '.') {
          if (s[i] >= '5') {
            if (s[i - 1] == '.') s[i - 2]++;
            else s[i - 1]++;
            s[i] = '0';
          }
          if (s[i] > '9') {
            if (s[i - 1] == '.') s[i - 2]++;
            else s[i - 1]++;
            s[i] -= '9' + 1;
          }
        }
      }
    }
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '.') {
        if (i + 2 < s.length()) cout << '.' << s[i + 1] << s[i + 2] << endl;
        else cout << '.' << s[i + 1] << '0' << endl;
        break;
      }
      else cout << s[i];
    }
  }
  return 0;
}
