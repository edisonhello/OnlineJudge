#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000 + 5, P = 1087;
unsigned long long _hash[maxn], p[maxn];
string s, t;
int T, Q;

inline unsigned long long Hash(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T;
  while (T--) {
    cin >> t;
    _hash[0] = t[0];
    for (int i = 1; i < t.size(); ++i) _hash[i] = _hash[i - 1] * P + t[i];
    p[0] = 1;
    for (int i = 1; i < t.size(); ++i) p[i] = p[i - 1] * P;
    cin >> Q;
    while (Q--) {
      cin >> s;
      int cnt = 0;
      unsigned long long h = s[0];
      for (int i = 1; i < s.size(); ++i) h = h * P + s[i];
      for (int i = 0; i < t.size(); ++i) {
        if (i + s.size() > t.size()) break;
        if (Hash(i, i + s.size() - 1) == h) ++cnt;
      }
      cout << cnt << '\n';
    }
  }
  return 0;
}

inline unsigned long long Hash(int L, int R) {
  if (L == 0) return _hash[R];
  return _hash[R] - p[R - L + 1] * _hash[L - 1];
}
