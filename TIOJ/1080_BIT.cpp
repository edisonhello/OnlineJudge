#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <map>
#define getchar getchar_unlocked
#define lowbit(x) (x) & (-x)

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

const int maxn = 100000 + 5;
int BIT[maxn], n, kase, A[maxn], B[maxn];
long long ans;
std::map<int, int> m;

inline int sum(int);
inline void add(int, int);

int main() {
  while (rit(n), n) {
    memset(BIT, 0, sizeof(BIT));
    ans = 0;
    m.clear();
    for (int i = 0; i < n; ++i) rit(A[i]), B[i] = A[i];
    std::sort(B, B + n);
    for (int i = 0; i < n; ++i) m[B[i]] = i + 1;
    for (int i = 0; i < n; ++i) {
      ans += i - sum(m[A[i]]);
      add(m[A[i]], 1);
    }
    printf("Case #%d: %lld\n", ++kase, ans);
  }
}

inline int sum(int x) {
  int ret = 0;
  while (x) ret += BIT[x], x -= lowbit(x);
  return ret;
}

inline void add(int x, int v) {
  while (x <= n) BIT[x] += v, x += lowbit(x);
}
