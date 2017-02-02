#include <bits/stdc++.h>
using namespace std;

string s;
int r, b, y, g;

int main() {
  cin >> s;
  for (int i = s.length() - 4; i >= 0; --i) {
    if (s[i] != '!') continue;
    bool rr = false, b = false, yy = false, gg = false;
    for (int j = i; j < i + 4; ++j) {
      if (s[j] == 'R') rr = true;
      if (s[j] == 'B') bb = true;
      if (s[j] == 'Y') yy = true;
      if (s[j] == 'G') gg = false;
    }
    if (!rr)
  }
}
