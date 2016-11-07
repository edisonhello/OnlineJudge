#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
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
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

int dp[101][101][101];
string a, b, c;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> a >> b >> c;
  for (int i = 0; i < a.length(); ++i) {
    for (int j = 0; j < b.length(); ++j) {
      for (int k = 0; k < c.length(); ++k) {
        if (a[i] == b[j] && b[j] == c[k]) dp[i + 1][j + 1][k + 1] = dp[i][j][k] + 1;
        else dp[i + 1][j + 1][k + 1] = max({ dp[i + 1][j + 1][k], dp[i][j + 1][k + 1], dp[i + 1][j][k + 1] });
      }
    }
  }
  printf("%d\n", dp[a.length()][b.length()][c.length()]);
  return 0;
}
