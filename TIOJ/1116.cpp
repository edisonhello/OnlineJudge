#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
  while (cin >> s) {
    // cout << "jizz\n";
    for (int i = 0; i < 4; ++i) {
      // cout << "jizz\n";
      if (s[i] == 'b') cout << 'X';
      else if (s[i] == 'c') {
        string ret = ""; bool p = false;
        if (i > 0) { if (s[i - 1] == 'b' || s[i - 1] == 'c') ret += 'A', p = true; }
        else { if (s[3] == 'b' || s[3] == 'c') ret += 'A', p = true; }
        if (i < 3) { if (s[i + 1] == 'b' || s[i + 1] == 'c') ret += 'B', p = true; }
        else { if (s[0] == 'b' || s[0] == 'c') ret += 'B', p = true; }
        if (i < 2) { if (s[i + 2] == 'b' || s[i + 2] == 'c') ret += 'C', p = true; }
        else { if (i >= 2) if (s[i - 2] == 'b' || s[i - 2] == 'c') ret += 'C', p = true; }
        if (!p) cout << "Y";
        else cout << ret;
      } else if (s[i] == 'a') {
        string ret = ""; bool p = false;
        if (i > 0) { if (s[i - 1] == 'b' || s[i - 1] == 'c') ret += 'A', p = true; }
        else { if (s[3] == 'b' || s[3] == 'c') ret += 'A', p = true; }
        if (i < 3) { if (s[i + 1] == 'b' || s[i + 1] == 'c') ret += 'B', p = true; }
        else { if (s[0] == 'b' || s[0] == 'c') ret += 'B', p = true; }
        if (i < 2) { if (s[i + 2] == 'b' || s[i + 2] == 'c') ret += 'C', p = true; }
        else { if (i >= 2) if (s[i - 2] == 'b' || s[i - 2] == 'c') ret += 'C', p = true; }
        if (!p) cout << "Y";
        else cout << ret;
      }
      if (i < 3) cout << ", ";
      else cout << endl;
    }
  }
  return 0;
}
