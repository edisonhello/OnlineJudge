#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000 + 5, _P[2] = { 719, 233 }, _MOD[2] = { 479001599, 1073807359 };
string s;
int P, MOD;
long long _hash[maxn], p[maxn];
vector<int> fac;

bool check(int);
inline long long Hash(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  srand(time(NULL));
  while (cin >> s, s != ".") {
    int randp = rand() % 2, randmod = rand() % 2;
    P = _P[randp], MOD = _MOD[randmod];
    _hash[0] = s[0];
    for (int i = 1; i < s.length(); ++i) _hash[i] = (_hash[i - 1] * P + s[i]) % MOD;
    p[0] = 1;
    for (int i = 1; i < s.length(); ++i) p[i] = (p[i - 1] * P) % MOD;
    fac.clear();
    for (int i = 1; i <= s.length(); ++i) if ((int)s.length() % i == 0) fac.push_back(i);
    for (int i : fac) if (check(i)) { cout << (int)s.length() / i << '\n'; break; }
  }
  return 0;
}

inline long long Hash(int L, int R) {
  if (L == 0) return _hash[R];
  return (((_hash[R] - p[R - L + 1] * _hash[L - 1]) % MOD) + MOD) % MOD;
}

bool check(int len) {
  long long h = Hash(0, len - 1);
  for (int i = len; i < s.length(); i += len) {
    if (Hash(i, i + len - 1) != h) return false;
  }
  return true;
}
