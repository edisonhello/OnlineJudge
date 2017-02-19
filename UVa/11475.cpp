#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 5;
string s, t;
int z[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  while (cin >> s) {
    t = s;
    string tmp = ".";
    int len = s.length();
    for (int i = 0; i < s.length(); ++i) tmp += s[i], tmp += ".";
    s = tmp;
    int L = 0, R = 0;
    memset(z, 0, sizeof(z));
    for (int i = 1; i < s.length(); ++i) {
      z[i] = (R > i) ? min(z[L * 2 - i], R - i) : 1;
      while (i + z[i] < s.length() && i - z[i] >= 0 && s[i + z[i]] == s[i - z[i]]) ++z[i];
      if (i + z[i] > R) R = i + z[i], L = i;
    }
    int ans;
    for (int i = 0; i < s.length(); ++i) {
      if (i & 1) {
        int pal = (z[i] - 2) >> 1;
        int idx = (i - 1) >> 1;
        if (idx + pal == len - 1) { ans = idx - 1 - pal; break; }
      } else {
        int pal = (z[i] - 1) >> 1;
        int idx = i >> 1;
        if (idx + pal - 1 == len - 1) { ans = idx - 1 - pal; break; }
      }
    }
    cout << t;
    t = t.substr(0, ans + 1);
    reverse(t.begin(), t.end());
    cout << t << '\n';
  }
  return 0;
}
