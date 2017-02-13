#include <iostream>
#include <cstring>
#include <algorithm>
#define Lc(id) (id << 1)
#define Rc(id) (id << 1 | 1)
using namespace std;

const int maxn = 50000 + 5;
struct Int { int a, b, c; } in[maxn];
struct Seg { int sum, tag; } seg[maxn << 2];
int N;

bool cmp(const Int& i1, const Int& i2) {
  return i1.b == i2.b ? i1.c == i2.c ? i1.a < i2.a : i1.c > i2.c : i1.b < i2.b;
}

int query(int, int, int, int, int);
int bs(int, int, int);
void modify(int, int, int, int, int);
void push(int, int, int);
void pull(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> in[i].a >> in[i].b >> in[i].c;
  sort(in, in + N, cmp);
  for (int i = 0; i < N; ++i) {
    int q = query(1, 0, maxn, in[i].a, in[i].b);
    if (in[i].c <= q) continue;
    int x = bs(in[i].a, in[i].b, in[i].c - q);
    modify(1, 0, maxn, x, in[i].b);
  }
  cout << query(1, 0, maxn, 0, maxn) << '\n';
  return 0;
}

int query(int id, int L, int R, int l, int r) {
  push(id, L, R);
  if (L > r || l > R) return 0;
  if (L >= l && R <= r) return seg[id].sum;
  int M = (L + R) >> 1;
  return query(Lc(id), L, M, l, r) + query(Rc(id), M + 1, R, l, r);
}

int bs(int a, int b, int c) {
  int L = a, R = b;
  while (L < R) {
    int M = (L + R) >> 1;
    int q = query(1, 0, maxn, M, b);
    if (b - M + 1 - q > c) L = M + 1;
    else R = M;
  }
  return L;
}

void modify(int id, int L, int R, int l, int r) {
  push(id, L, R);
  if (L > r || l > R) return;
  if (L >= l && R <= r) {
    seg[id].sum = (R - L + 1), seg[id].tag = 1;
    return;
  }
  int M = (L + R) >> 1;
  modify(Lc(id), L, M, l, r); modify(Rc(id), M + 1, R, l, r);
  pull(id);
}

void push(int id, int L, int R) {
  if (L == R) return;
  if (!seg[id].tag) return;
  int M = (L + R) >> 1;
  seg[Lc(id)].sum = M - L + 1; seg[Lc(id)].tag = 1;
  seg[Rc(id)].sum = R - M; seg[Rc(id)].tag = 1;
  seg[id].tag = 0;
}

void pull(int id) {
  seg[id].sum = seg[Lc(id)].sum + seg[Rc(id)].sum;
}
