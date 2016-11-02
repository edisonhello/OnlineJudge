#include <cstdio>
#include <algorithm>
#include <iostream>
//#define int long long
#ifdef linux
#define getchar getchar_unlocked
#endif
using namespace std;

char __c;
bool flag;

struct Node {
  long long gcd, sm;
};

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

int N, Q, l, r, k, c;
long long q, t, x[100005];
Node seg[400005];
void build(int, int, int);
void modify(int, int, int, int, int);
long long query(int, int, int, int, int);
long long queryL(int, int, int, int, int);

inline int Lc(int x) { return x * 2; }
inline int Rc(int x) { return x * 2 + 1; }

int main() {
  rit(N, Q);
  x[0] = 0;
  for (int i = 1; i <= N; ++i) rit(x[i]);
  build(1, N, 1);
  while (Q--) {
    rit(c);
    if (c == 1) {
      rit(l, r, k);
      modify(1, N, 1, l, k), modify(1, N, 1, r + 1, -k);
    }
    if (c == 2) {
      rit(l, r);
      if (l == r) { printf("%lld\n", queryL(1, N, 1, 1, l)); continue; }
      q = query(1, N, 1, l + 1, r);
      t = queryL(1, N, 1, 1, l);
      printf("%lld\n", __gcd(q, t));
    }
  }
  return 0;
}

void build(int L, int R, int id) {
  if (L == R) { seg[id].sm = x[L] - x[L - 1]; seg[id].gcd = abs(seg[id].sm); return; }
  int M = (L + R) / 2;
  build(L, M, Lc(id)); build(M + 1, R, Rc(id));
  seg[id].gcd = abs(__gcd(seg[Lc(id)].gcd, seg[Rc(id)].gcd));
  seg[id].sm = seg[Lc(id)].sm + seg[Rc(id)].sm;
}

void modify(int L, int R, int id, int x, int k) {
  if (x < L || x > R) return;
  if (x == L && L == R) { seg[id].sm += k; seg[id].gcd = abs(seg[id].sm); return; }
  int M = (L + R) / 2;
  if (x <= M) modify(L, M, Lc(id), x, k);
  if (x > M) modify(M + 1, R, Rc(id), x, k);
  seg[id].gcd = __gcd(seg[Lc(id)].gcd, seg[Rc(id)].gcd);
  seg[id].sm = seg[Lc(id)].sm + seg[Rc(id)].sm;
}

long long query(int L, int R, int id, int l, int r) {
  if (L > r || l > R) return 0;
  if (l <= L && R <= r) return seg[id].gcd;
  int M = (L + R) / 2;
  long long q1 = query(L, M, Lc(id), l, r), q2 = query(M + 1, R, Rc(id), l, r);
  return __gcd(q1, q2);
}

long long queryL(int L, int R, int id, int l, int r) {
  if (L > r || l > R) return 0;
  if (l <= L && R <= r) return seg[id].sm;
  int M = (L + R) / 2;
  long long q1 = queryL(L, M, Lc(id), l, r), q2 = queryL(M + 1, R, Rc(id), l, r);
  return q1 + q2;
}
