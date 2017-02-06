#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 10000 + 5, MOD = 1073807359, P = 157;
string s;
int K, _hash[maxn], p[maxn];
set<string> ans;

bool check(int);
inline int Hash(int, int);

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> s >> K;
  if (s.length() <= 10) {
    for (int len = 1; len <= s.length(); ++len) {
      set<string> ret;
      for (int i = 0; i < s.length() - len + 1; ++i) {
        string a = s.substr(i, len);
        int cnt = 0;
        for (int j = 0; j < s.length() - len + 1; ++j) if (s.substr(j, len) == a) cnt++;
        if (cnt == K) ret.insert(a);
      }
      if (ret.size()) ans = ret;
    }
    for (string c : ans) cout << c << '\n';
    return 0;
  }
  _hash[0] = s[0];
  for (int i = 1; i < s.length(); ++i) _hash[i] = (_hash[i - 1] * P + s[i]) % MOD;
  p[0] = 1;
  for (int i = 1; i < s.length(); ++i) p[i] = (p[i - 1] * P) % MOD;
  int L = 1, R = s.length();
  while (L < R) {
    int M = (L + R) >> 1;
    if (check(M)) L = M + 1;
    else R = M;
  }
  for (auto i : ans) cout << i << '\n';
  return 0;
}

bool check(int x) {
  set<string> ret;
  set<int> jizz;
  map<int, int> m;
  for (int i = 0; i < s.length(); ++i) {
    if (i + x > s.length()) break;
    m[Hash(i, i + x - 1)]++;
  }
  for (auto : m) if (m.second == K) return true;
  if (ret.size()) ans = ret;
  return ret.size();
}

inline int Hash(int i, int j) {
  if (i == 0) return _hash[j];
  return ((_hash[j] - p[j - i + 1] * _hash[i - 1] + MOD) % MOD + MOD) % MOD;
}
