#include "lib1338.h"
#include <algorithm>
#include <iostream>
#include <utility>
#define PLL pair<long long, long long>
using namespace std;

const long long INF = (1 << 63) - 1;

struct Node {
  long long gcd, mn;
};

Node seg[4000010];
long long* a;
int n;

inline int Lc(int id) {return id * 2;}
inline int Rc(int id) {return id * 2 + 1;}
PLL q(int, int, int, int, int);
void build(int, int, int);

void init(int N, long long C[]) {
  n = N;
  a = C;
  build(0, n - 1, 1);
}

int query(int L, int R) {
  PLL pll = q(0, n - 1, L, R - 1, 1);
  return pll.first == pll.second;
  // for (int i = L; i < R; ++i) if (a[i] == num) return 1;
  // return 0;
}

// int gcd(int a, int b) {
//   if (a == 0) return b;
//   if (b == 0) return a;
//   if (a > b) return gcd(a % b, b);
//   else return gcd(b % a, a);
// }

void build(int l, int r, int id) {
  if (l == r) {seg[id].gcd = a[l]; seg[id].mn = a[l]; return;}
  int m = (l + r) / 2;
  build(l, m, Lc(id)); build(m + 1, r, Rc(id));
  // bool p = false;
  // for (int i = l; i <= r; ++i) {
  //   if (seg[Lc(id)].num % a[i] == 0 && seg[Rc(id)].num % a[i] == 0) {
  //     seg[id].b = true; seg[id].num = a[i]; p = true;
  //     break;
  //   }
  // }
  // if (!p) seg[id].b = false;
  seg[id].gcd = __gcd(seg[Lc(id)].gcd, seg[Rc(id)].gcd);
  seg[id].mn = min(seg[Lc(id)].mn, seg[Rc(id)].mn);
}

PLL q(int L, int R, int ql, int qr, int id) {
  // cout << seg[id].num << " " << seg[id].b << endl;
  if (ql > R || qr < L) return make_pair(INF, 0);
  if (L >= ql && R <= qr) {
    return make_pair(seg[id].mn, seg[id].gcd);
  }
  int m = (L + R) / 2;
  PLL q1 = q(L, m, ql, qr, Lc(id)), q2 = q(m + 1, R, ql, qr, Rc(id));
  if (q1.second == 0) return q2;
  else if (q2.second == 0) return q1;
  else {
    return make_pair(min(q1.first, q2.first), __gcd(q1.second, q2.second));
  }
}
