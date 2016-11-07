#include <cstdio>
#include <algorithm>
#include <utility>
#define getchar getchar_unlocked
#define INF (long long)(1 << 30)
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

struct Interval {
  long long mn, mx;
};

Interval t[20][100005];
int n, m, qi, qj, p;
long long H[100005], ans;

int main() {
  rit(n, m);
  for (int i = 1; i <= n; ++i) rit(H[i]);
  for (int i = 1; i <= n; ++i) t[0][i].mn = H[i], t[0][i].mx = H[i];
  for (int i = 1; (1 << i) - 1 <= n; ++i) {
    for (int j = 1; j + (1 << (i - 1)) <= n; ++j) {
      t[i][j].mn = min(t[i - 1][j].mn, t[i - 1][j + (1 << (i - 1))].mn);
      t[i][j].mx = max(t[i - 1][j].mx, t[i - 1][j + (1 << (i - 1))].mx);
    }
  }
  while (m--) {
    rit(qi, qj);
    p = 31 - __builtin_clz(qj - qi + 1);
    ans = max(t[p][qi].mx, t[p][qj - (1 << p) + 1].mx) - min(t[p][qi].mn, t[p][qj - (1 << p) + 1].mn);
    printf("%lld\n", ans);
  }
  return 0;
}
