#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF (1 << 30)
#define getchar getchar_unlocked
#define abs(x) (x) > 0 ? (x) : -(x)
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

int T, h[1005], N, mn, best, tot;
inline int add(int);

int main() {
  rit(T);
  while (T--) {
    rit(N); tot = 0;
    for (int i = 1; i <= N; ++i) rit(h[i]);
    h[N + 1] = h[N];
    for (int i = 1; i <= N; ++i) {
      mn = INF;
      for (int j = 1; j <= N; ++j) {
        int sw = -add(i) - add(j);
        swap(h[i], h[j]);
        sw += add(i) + add(j);
        swap(h[i], h[j]);
        if (sw < mn) mn = sw, best = j;
      }
      printf("%d ", best);
    }
    puts("");
  }
  return 0;
}

inline int add(int i) {
  int ret = 0;
  if (i > 1) ret += abs(h[i] - h[i - 1]);
  if (i < N) ret += abs(h[i] - h[i + 1]);
  return ret;
}
