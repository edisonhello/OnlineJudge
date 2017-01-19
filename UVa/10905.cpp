#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

string s[51];
int n;
bool v[10];

string solve(int);
int low(int);

int main() {
  while (cin >> n, n) {
    for (int i = 0; i < n; ++i) cin >> s[i];
    memset(v, false, sizeof(v));
    for (int i = 0; i < n; ++i) v[s[i][0] - '0'] = true;
    auto cmp = [](const string& a, const string& b) -> bool {
      for (int i = 0; i < min(a.length(), b.length()); ++i) if (a[i] != b[i]) return a[i] > b[i];
      if (a.length() > b.length()) return low(b[0] - '0') > a[b.length()] - '0';
      else if (b.length() > a.length()) return low(a[0] - '0') > b[a.length()] - '0';
      return a > b;
    };
    sort(s, s + n, cmp);
    string ret = "";
    for (int i = 0; i < n; ++i) ret += s[i];
    cout << ret << '\n';
  }
  return 0;
}

// string solve(int i) {
//   if (i >= n) return "";
//   int j = i;
//   for (; j < n; ++j) if (s[j][0] != s[i][0]) break;
//   string ret = s[i] + solve(i + 1);
//   for (int k = i + 1; k < j; ++k) ret = max(ret, s[])
// }

int low(int x) {
  x--;
  while (x >= 0) {
    if (v[x]) return x;
    x--;
  }
  return 0;
}
