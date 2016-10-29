#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

char __c;
bool flag;

template <typename T>
inline bool rit(T& x) {
  __c = 0, flag = false;
  while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
  __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
  while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
  if (flag) x = -x;
  return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) {return rit(x) && rit(args...);}

string s;
int N, a, z[20000010];

int main() {
  rit(N);
  for (int i = 0; i < N; ++i) s += '.', rit(a), s += (a + '0');
  s += '.';
  // cout << s << endl;
  int L = 0, R = 0, mx = 0, p = 0;
  N = N * 2 + 1;
  for (int i = 1; i < N; ++i) {
    z[i] = (R > i) ? min(z[2 * L - i], R - i) : 1;
    while (i + z[i] < N && i - z[i] >= 0 && s[i - z[i]] == s[i + z[i]]) z[i]++;
    if (i + z[i] > R) L = i, R = i + z[i];
  }
  for (int i = 1; i < N; ++i) if (z[i] > mx) mx = z[i];
  printf("%d\n", mx - 2);
  return 0;
}
