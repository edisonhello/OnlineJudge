#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
#include <vector>
#include <iomanip>
using namespace std;

const int maxn = 1000000 + 5;
string s, t;
int z[maxn * 6], len, L, R;
vector<int> ans;

inline void Z();

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> s;
  len = (int)s.length();
  s = s + s;
  t = ".";
  for (int i = 0; i < s.length(); ++i) t += s[i], t += '.';
  Z();
  int mid = len;
  for (int i = mid, cnt = 0; i < t.length() && cnt < len; i += 2, ++cnt) if (z[i] - 1 >= len) ans.push_back((i - mid) >> 1);
  if (ans.size() == 0) { cout << "none\n"; return 0; }
  cout << ans.size() << ":";
  for (int a : ans) if (a < len) cout << ' ' << a;
  return 0;
}

inline void Z() {
  int L = 0, R = 0;
  for (int i = 1; i < t.length(); ++i) {
    z[i] = (R > i) ? min(z[L * 2 - i], R - i) : 1;
    while (i + z[i] < t.length() && i - z[i] >= 0 && t[i + z[i]] == t[i - z[i]]) z[i]++;
    if (i + z[i] > R) L = i, R = z[i] + i;
  }
}
