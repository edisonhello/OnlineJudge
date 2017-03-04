#include <bits/stdc++.h>
using namespace std;

const int maxn = 50000 + 5, P = 1933;
unsigned long long _hash[2][maxn], p[maxn];
string s, t;

bool check(int);
inline unsigned long long Hash(int, int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  getline(cin, s); getline(cin, t);
  p[0] = 1ull;
  for (int i = 1; i < maxn; ++i) p[i] = p[i - 1] * P;
  _hash[0][0] = s[0];
  for (int i = 1; i < s.length(); ++i) _hash[0][i] = _hash[0][i - 1] * P + s[i];
  _hash[1][0] = t[0];
  for (int i = 1; i < t.length(); ++i) _hash[1][i] = _hash[1][i - 1] * P + t[i];
  int d = 1, ans = 0;
  while (d <= t.length()) d <<= 1;
  while (d >>= 1) if (ans + d <= t.length()) if (check(ans + d)) ans += d;
  cout << ans << '\n';
  return 0;
}

bool check(int len) {
  set<unsigned long long> st;
  for (int i = 0; i < s.length(); ++i) {
    if (i + len > s.length()) break;
    st.insert(Hash(0, i, i + len - 1));
  }
  for (int i = 0; i < t.length(); ++i) {
    if (i + len > t.length()) break;
    if (st.count(Hash(1, i, len + i - 1))) return true;
  }
  return false;
}

inline unsigned long long Hash(int id, int L, int R) {
  if (L == 0) return _hash[id][R];
  return _hash[id][R] - p[R - L + 1] * _hash[id][L - 1];
}
