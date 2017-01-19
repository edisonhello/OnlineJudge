#include <bits/stdc++.h>
#define int long long
using namespace std;

string s;
int t;

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> s >> t;
  int x = 0, y = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == 'R') x++;
    if (s[i] == 'L') x--;
    if (s[i] == 'U') y++;
    if (s[i] == 'D') y--;
  }
  cout << x * t << ' ' << y * t << '\n';
  return 0;
}
