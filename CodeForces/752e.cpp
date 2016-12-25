#include <cstdio>
#include <iostream>
#include <queue>
#include <climits>
#include <cstdlib>
// #define getchar getchar_unlocked
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

struct Treap {
  Treap *l, *r;
  long long val, sz;
  int pri;
  Treap(): l(NULL), r(NULL) {
    val = 0;
    sz = 1;
    pri = rand();
  }
  Treap(long long v): l(NULL), r(NULL) {
    val = v;
    sz = 1;
    pri = rand();
  }
  inline int Lsz() { return l ? l->sz : 0; }
  inline int Rsz() { return r ? r->sz : 0; }
} *root;

long long n, k, a;
Treap* merge(Treap*, Treap*);
void insert(Treap*&, long long);
void del(Treap*&, long long);
void split(Treap*, long long, Treap*&, Treap*&);
void pull(Treap*);
long long Max(Treap*);
long long kth(Treap*, long long);
long long Min(Treap*);
void print(Treap*);

int main() {
  srand(7122);
  rit(n, k); root = NULL;
  for (int i = 0; i < n; ++i) rit(a), insert(root, a);
  long long ans = -1;
  long long SZ = n;
  while (true) {
    long long big = kth(root, 1);
    if (SZ >= k) ans = max(ans, kth(root, k));
    if (big <= 1) {
      if (SZ < k) { cout << -1 << '\n'; return 0; }
      else break;
    }
    if (big / 2 < kth(root, SZ) && SZ >= k) break;
    del(root, big);
    insert(root, big / 2);
    insert(root, big - (big / 2));
    SZ++;
  }
  ans = max(ans, kth(root, k));
  cout << ans << '\n';
  return 0;
}

Treap* merge(Treap* a, Treap* b) {
  if (!a || !b) return a ? a : b;
  if (a->pri > b->pri) {
    a->r = merge(a->r, b);
    pull(a);
    return a;
  }
  b->l = merge(a, b->l);
  pull(b);
  return b;
}

void split(Treap* treap, long long k, Treap*& a, Treap*& b) {
  if (!treap) { a = b = NULL; return; }
  if (treap->val <= k) {
    a = treap;
    split(treap->r, k, a->r, b);
    pull(a);
    return;
  } else {
    b = treap;
    split(treap->l, k, a, b->l);
    pull(b);
  }
}

void pull(Treap* treap) {
  if (!treap) return;
  treap->sz = treap->Lsz() + treap->Rsz() + 1;
}

void insert(Treap*& treap, long long v) {
  // if (treap->val )
  Treap *a, *b;
  split(treap, v - 1, a, b);
  treap = merge(merge(a, new Treap(v)), b);
}

void del(Treap*& treap, long long v) {
  int add = 0;
  Treap *a, *b, *c, *d;
  split(treap, v, a, b);
  split(a, v - 1, c, d);
  if (d && d->sz > 1) add = d->sz - 1;
  treap = merge(c, b);
  for (int i = 0; i < add; ++i) insert(treap, v);
  delete d;
}

long long Max(Treap* treap) {
  if (treap->r) return Max(treap->r);
  return treap->val;
}

long long kth(Treap* treap, long long k) {
  if (treap->Rsz() + 1 == k) return treap->val;
  if (treap->Rsz() + 1 > k) return kth(treap->r, k);
  else return kth(treap->l, k - treap->Rsz() - 1);
}

long long Min(Treap* treap){
  if (treap->l) return Min(treap->l);
  return treap->val;
}
