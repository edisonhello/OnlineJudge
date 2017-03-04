#include <bits/stdc++.h>
using namespace std;

set<string> osas;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  string s; while (cin >> s) osas.insert(s);
  for (string i : osas) {
    for (int j = 1; j < i.length(); ++j) {
      if (osas.count(i.substr(0, j)) && osas.count(i.substr(j, i.length() - j + 1))) { cout << i << '\n'; break; }
    }
  }
  return 0;
}
