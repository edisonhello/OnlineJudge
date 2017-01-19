#include <bits/stdc++.h>
using namespace std;

const int MOD = 433494437, P = 233, maxn = 5000 + 5;
string s[2];
long long _hash[2][maxn], p[maxn];

inline long long Hash(int, int, int);
bool check(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> s[0] >> s[1];
  for (int k = 0; k < 2; ++k) {
    _hash[k][0] = s[k][0];
    for (int i = 1; i < s[k].length(); ++i) _hash[k][i] = (_hash[k][i - 1] * P + s[k][i]) % MOD;
  }
  p[0] = 1;
  for (int i = 1; i < max(s[0].length(), s[1].length()); ++i) p[i] = (p[i - 1] * P) % MOD;
  int d = 1, len = min(s[0].length(), s[1].length());
  while (d < min(s[0].length(), s[1].length())) d <<= 1;
  while (d >>= 1) if (check(len - d)) len -= d;
  cout << len << '\n';
  return 0;
}

inline long long Hash(int k, int i, int j) {
  if (i == 0) return _hash[k][0];
  return ((_hash[k][j] - p[j - i + 1] * _hash[k][i - 1]) % MOD + MOD) % MOD;
}

bool check(int len) {
  for (int i = 0; i < s[0].length(); ++i) {
    if (i + len > s[0].length()) break;
    int h = Hash(0, i, i + len - 1);
    int cnt = 0;
    for (int j = 0; j < s[1].length(); ++j) {
      if (j + len > s[1].length()) break;
      if (Hash(1, j, j + len - 1) == h) cnt++;
    }
    if (cnt > 1) continue;
    int cnt2 = 0;
    for (int j = 0; j < s[0].length(); ++j) {
      if (j + len > s[0].length()) break;
      if (Hash(0, j, j + len - 1) == h) cnt2++;
    }
    if (cnt2 < 1) return true;
  }
  return false;
}
