#include <cstdio>
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
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

int N, T[5000005], seg[20000005], M, a, b;
void build(int, int, int);
int query(int, int, int, int, int);

inline int Lc(int x) { return x * 2; }
inline int Rc(int x) { return x * 2 + 1; }
int main() {
  rit(N);
  for (int i = 1; i <= N; ++i) rit(T[i]);
  build(1, N, 1);
  rit(M);
  while (M--) {
    rit(a, b);
    if (a > b) swap(a, b);
    printf("%d\n", query(1, N, 1, a, b));
  }
  return 0;
}

void build(int L, int R, int id) {
  if (L == R) { seg[id] = T[L]; return; }
  int M = (L + R) >> 1;
  build(L, M, Lc(id)); build(M + 1, R, Rc(id));
  seg[id] = max(seg[Lc(id)], seg[Rc(id)]);
}

int query(int L, int R, int id, int l, int r) {
  if (L > r || l > R) return 0;
  if (L >= l && R <= r) return seg[id];
  int M = (L + R) >> 1;
  return max(query(L, M, Lc(id), l, r), query(M + 1, R, Rc(id), l, r));
}
