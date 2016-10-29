#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>
#define getchar getchar_unlocked
#define INF (1 << 30)
using namespace std;

char __c;
bool flag;

template <typename T>
inline bool rit(T& x) {
  __c = 0; flag = false;
  while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
  __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
  while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
  if (flag) x = -x;
  return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) {return rit(x) && rit(args...);}

int m, n, mp[3005][3005], mx, dp[3005][3005];
// vector<bitset<3005>> v(3005);
void greedy(int, int, int);

int main() {
  rit(m, n);
  for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) rit(mp[i][j]);
  mx = -INF;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i - 1 >= 0 && j - 1 >= 0) dp[i][j] = max(0, mp[i][j] + max(dp[i - 1][j], dp[i][j - 1]));
      else if (i - 1 >= 0) dp[i][j] = max(0, mp[i][j] + dp[i - 1][j]);
      else if (j - 1 >= 0) dp[i][j] = max(0, mp[i][j] + dp[i][j - 1]);
      else dp[i][j] = max(0, mp[i][j]);
    }
  }
  for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) if (dp[i][j] > mx) mx = dp[i][j];
  printf("%d\n", mx);
  return 0;
}
