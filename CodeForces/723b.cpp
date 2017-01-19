#include <iostream>
#include <string>
#include <algorithm>
#include <ctype.h>
using namespace std;

string s;
int n, st, in, Max;

int main() {
  cin >> n >> s;
  st = 0;
  bool p = false;
  bool b = false;
  for (int i = 0; i < n; ++i) {
    // if (s[st] == '_' || s[st] == '(' || s[st] == ')') st++;
    if (s[i] == ')' && b && p) in++, st = i + 1, p = false, b = false;
    if (s[i] == ')' && !p) b = false;
    if (s[i] == '_' && p) {
      if (b) in++;
      if (!b) Max = max(Max, i - st);
      st = i + 1, p = false;
    }
    if (s[i] == '(' && p) {
      if (!b) Max = max(Max, i - st);
      st = i + 1, p = false;
    }
    if (s[i] == '(') b = true;
    if (isalpha(s[i])) p = true;
  }
  cout << Max << ' ' << in << '\n';
  return 0;
}
