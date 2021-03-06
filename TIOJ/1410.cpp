#include <cstdio>
#include <algorithm>
#define getchar getchar_unlocked
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

struct S {
  int t, f;
  bool operator<(const S& s) const {
    return t == s.t ? f > s.f : t < s.t;
  }
};

int n, ans, now;
S s[2000005];


int main() {
  while (rit(n)) {
    for (int i = 0; i < n; ++i) rit(s[i * 2].t, s[i * 2 + 1].t), s[i * 2].f = 1, s[i * 2 + 1].f = -1;
    sort(s, s + 2 * n);
    now = 0; ans = 0;
    for (int i = 0; i < 2 * n; ++i) {
      now += s[i].f; ans = max(ans, now);
    }
    printf("%d\n", ans);
  }
  return 0;
}
