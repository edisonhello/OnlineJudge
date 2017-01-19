#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
  while (cin >> s) {
    for (int i = 1; i <= s.length(); ++i) {
      if (s.length() % i) continue;
      string t = "";
      for (int j = 0; j < s.length() / i; ++j) t += s.substr(0, i);
      if (s == t) { cout << s.length() / i << '\n'; break; }
    }
  }
}
