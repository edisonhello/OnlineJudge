#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  string s;
  int mx = 0; int cnt = 0;
  cin >> n;
  cin >> s;
  int prev = 0;
  bool p = true;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '_' && p && (i == 0 || s[i - 1] != '(' && s[i - 1] != ')')) {
      if (i - prev > mx) mx = i - prev;
      prev = i + 1;
    } else if (s[i] == '(') {
      if (i - prev > mx) mx = i - prev;
      prev = i + 1;
      p = false;
    } else if (s[i] == ')') {
      if (i - 1 >= 0 && s[i - 1] != '_' && s[i - 1] != '(') cnt++;
      prev = i + 1;
      p = true;
    } else if (!p && s[i] == '_') {
      if (i - 1 >= 0 && s[i - 1] != '_' && s[i - 1] != '(') cnt++;
      prev = i + 1;
    }
  }
  cout << mx << ' ' << cnt << endl;
  return 0;
}
