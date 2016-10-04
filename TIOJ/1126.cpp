#include <string>
#include <iostream>
using namespace std;

string s;
int mx;

bool jizz(string ss) {
  string tmp = "";
  for (int i = ss.length() - 1; i >= 0; --i) tmp += ss[i];
  return ss == tmp;
}

int main() {
  while (cin >> s) {
    // cnt = 0;
    mx = 0;
    for (int i = 1; i <= s.length(); ++i) {
      for (int j = 0; j < s.length() - i + 1; ++j) {
        // cout << s.substr(j, i) << endl;
        if (jizz(s.substr(j, i))) if (i > mx) mx = i;
      }
    }
    cout << mx << endl;
  }
  return 0;
}
