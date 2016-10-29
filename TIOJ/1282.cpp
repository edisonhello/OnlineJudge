#include <cstdio>
#include <algorithm>
#include <iostream>
#define int long long
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
inline bool rit(T& x, Args& ...args) {return rit(x) && rit(args...);}

int N, Q, a[100005], x[100005], seg[400005], l, r, k, c;
void build(int, int, int);
void modify(int, int, int, int, int);
int query(int, int, int, int, int);

inline int Lc(int x) { return x * 2; }
inline int Rc(int x) { return x * 2 + 1; }

signed main() {
  rit(N, Q);
  x[0] = 0;
  for (int i = 1; i <= N; ++i) rit(x[i]), a[i] = x[i] - x[i - 1];
  build(1, N, 1);
  while (Q--) {
    rit(c);
    if (c == 1) {
      rit(l, r, k);
      modify(1, N, 1, l, k), modify(1, N, 1, r + 1, -k);
    }
    if (c == 2) {
      rit(l, r);
      printf("%lld\n", abs(query(1, N, 1, l + 1, r)));
    }
  }
  return 0;
}

void build(int L, int R, int id) {
  if (L == R) { seg[id] = a[L]; return; }
  int M = (L + R) / 2;
  build(L, M, Lc(id)); build(M + 1, R, Rc(id));
  seg[id] = __gcd(seg[Lc(id)], seg[Rc(id)]);
}

void modify(int L, int R, int id, int x, int k) {
  if (L == R) { seg[id] += k; return; }
  int M = (L + R) / 2;
  if (x <= M) modify(L, M, Lc(id), x, k);
  if (x > M) modify(M + 1, R, Rc(id), x, k);
  seg[id] = __gcd(seg[Lc(id)], seg[Rc(id)]);
}

int query(int L, int R, int id, int l, int r) {
  // cout << "L: " << L << " R: " << R << endl;
  if (L > r || l > R) return 0;
  if (l <= L && R <= r) return seg[id];
  int M = (L + R) / 2;
  int q1 = query(L, M, Lc(id), l, r), q2 = query(M + 1, R, Rc(id), l, r);
  if (!q1) return q2;
  if (!q2) return q1;
  return __gcd(q1, q2);
}
