#include "lib1871.h"
#include <iostream>
#include <utility>
#define INF 2147483647
using namespace std;

int* a;
int n, q;
int* seg;

inline int L(int x) {return x * 2;}
inline int R(int x) {return x * 2 + 1;}
int build(int, int, int);
int query(int, int, int, int, int);

int main() {
  n = futa::init();
  a = futa::momo_gives_you_list_of_futa();
  q = futa::momo_tells_you_q();
  seg = new int[4 * n];
  build(0, n - 1, 1);
  while (q--) {
    pair<int, int> p = futa::momo_asks();
    futa::you_tell_momo(query(0, n - 1, p.first, p.second, 1));
  }
}

int build(int l, int r, int id) {
  if (l == r) {seg[id] = a[l]; return seg[id];}
  int m = (l + r) / 2;
  int t1 = build(l, m, L(id)); int t2 = build(m + 1, r, R(id));
  return seg[id] = min(t1, t2);
}

int query(int l, int r, int ql, int qr, int id) {
  if (l > qr || r < ql) return INF;
  if (l >= ql && r <= qr) return seg[id];
  int m = (l + r) / 2;
  return min(query(l, m, ql, qr, L(id)), query(m + 1, r, ql, qr, R(id)));
}
