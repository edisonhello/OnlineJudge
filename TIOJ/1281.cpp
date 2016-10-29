#include <iostream>
#include <string>
#include <set>
#include <cstdio>
#define int long long
using namespace std;

int hsh[2][100010], p[2][100010], L, R, M, d;
int len;
string s;
const int MOD[2] = {479001599, 1073807359};
const int P[2] = {107, 103};
set<int> st;
int b;
int BS(int, int);
bool check(int, int);

inline int f(int i, int j, int h) {
  if (i == 0) return hsh[h][j];
  return (((hsh[h][j] - p[h][j - i + 1] * hsh[h][i - 1]) + 100 * MOD[h]) % MOD[h] + 100 * MOD[h]) % MOD[h];
}

signed main() {
  cin >> s;
  for (int h = 0; h < 2; ++h) {
    hsh[h][0] = s[0];
    for (int i = 1; i < s.length(); ++i) hsh[h][i] = (hsh[h][i - 1] * P[h] + s[i]) % MOD[h];
    p[h][0] = 1;
    for (int i = 1; i < s.length(); ++i) p[h][i] = (p[h][i - 1] * P[h]) % MOD[h];
  }
  d = 1, len = 0;
  while (d <= s.length() - 1) d <<= 1;
  while (d >>= 1) if (check(len + d, 0) && check(len + d, 1)) len += d;
  st.clear();
  for (int i = 0; i < s.length() - len + 1; ++i) {
    b = 0;
    if (st.find(f(i, i + len - 1, 0)) == st.end()) st.insert(f(i, i + len - 1, 0));
    else b++;
    if (st.find(f(i, i + len - 1, 1)) == st.end()) st.insert(f(i, i + len - 1, 1));
    else b++;
    if (b == 2) { cout << s.substr(i, len) << endl; break; }
  }
  return 0;
}

bool check(int len, int h) {
  st.clear();
  for (int i = 0; i < s.length() - len + 1; ++i) {
    if (st.find(f(i, i + len - 1, h)) == st.end()) st.insert(f(i, i + len - 1, h));
    else return true;
  }
  return false;
}
