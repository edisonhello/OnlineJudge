#include <iostream>
#include <string>
#define int long long
using namespace std;

const int maxn = 200000 + 5;
const int MOD = 1073807359, P = 157;
int _hash[2][maxn], p[maxn];
string s[2];

inline int f(int, int);
bool dq(int, int, int, int);

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> s[0] >> s[1];
  for (int k = 0; k < 2; ++k) {
    _hash[k][0] = s[k][0];
    for (int i = 1; i <= (int)s[k].length(); ++i) {
      _hash[k][i] = (_hash[k][i - 1] * P + s[k][i]);
      if (_hash[k][i] > MOD) _hash[k][i] %= MOD;
    }
    if (k) continue;
    p[0] = 1;
    for (int i = 1; i <= (int)s[k].length(); ++i) {
      p[i] = (p[i - 1] * P);
      if (p[i] > MOD) p[i] %= MOD;
    }
  }
  if (dq(0, (int)s[0].length(), 0, (int)s[1].length())) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}

inline int f(int i, int j, int id) {
  if (i == 0) return _hash[id][j];
  int h = _hash[id][j] - p[j - i + 1] * _hash[id][i - 1];
  if (h < 0) h = (h % MOD) + MOD;
  if (h > MOD) h %= MOD;
  return h;
}

bool dq(int L1, int R1, int L2, int R2) {
  if (((R1 - L1) & 1) || (R2 - L2) & 1) return f(L1, R1 - 1, 0) == f(L2, R2 - 1, 1);
  bool ret = f(L1, R1 - 1, 0) == f(L2, R2 - 1, 1);
  if (ret) return true;
  int M1 = (L1 + R1) >> 1, M2 = (L2 + R2) >> 1;
  ret |= (dq(L1, M1, L2, M2) && dq(M1, R1, M2, R2));
  ret |= (dq(L1, M1, M2, R2) && dq(M1, R1, L2, M2));
  return ret;
}
