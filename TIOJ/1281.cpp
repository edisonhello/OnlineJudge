#include <iostream>
#include <string>
#include <set>
#include <cstdio>
#include <map>
#define int long long
using namespace std;

int hsh[2][100010], p[2][100010], L, R, M, d;
int len;
string s;
const int MOD[2] = {370248451, 1073807359};
const int P[2] = {157, 131};
set<int> st;
map<int, int> mp;
int b;
int BS(int, int);
bool check(int);

inline int f(int i, int j, int h) {
  if (i == 0) return hsh[h][j];
  return (((hsh[h][j] - p[h][j - i + 1] * hsh[h][i - 1] + 10000000ll * MOD[h]) % MOD[h] + MOD[h]) % MOD[h] + MOD[h]) % MOD[h];
}

signed main() {
  cin >> s;
  for (int h = 0; h < 2; ++h) {
    hsh[h][0] = s[0];
    for (int i = 1; i < (long long)s.length(); ++i) hsh[h][i] = (hsh[h][i - 1] * P[h] + s[i]) % MOD[h];
    p[h][0] = 1;
    for (int i = 1; i < (long long)s.length(); ++i) p[h][i] = (p[h][i - 1] * P[h]) % MOD[h];
  }
  d = 1, len = 0;
  while (d <= s.length() - 1) d <<= 1;
  while (d >>= 1) if (check(len + d)) len += d;
  st.clear();
  for (int i = 0; i < (long long)s.length() - len + 1; ++i) {
    b = 0;
    if (st.find(f(i, i + len - 1, 0)) == st.end()) st.insert(f(i, i + len - 1, 0));
    else b++;
    if (st.find(f(i, i + len - 1, 1)) == st.end()) st.insert(f(i, i + len - 1, 1));
    else b++;
    if (b == 2) { cout << s.substr(i, len) << endl; break; }
  }
  return 0;
}

bool check(int len) {
  mp.clear();
  int ret = 0;
  bool pp;
  for (int i = 0; i < (long long)s.length() - len + 1; ++i) {
    pp = true;
    if (mp.find(f(i, i + len - 1, 0)) == mp.end()) mp[f(i, i + len - 1, 0)] = i, pp = false;
    if (mp.find(f(i, i + len - 1, 1)) == mp.end()) mp[f(i, i + len - 1, 1)] = i, pp = false;
    else if (mp[f(i, i + len - 1, 0)] != mp[f(i, i + len - 1, 1)]) {
      mp[f(i, i + len - 1, 0)] = i; mp[f(i, i + len - 1, 1)] = i;
      pp = false;
    }
    if (pp) return true;
  }
  return false;
}
