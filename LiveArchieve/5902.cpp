#include <bits/stdc++.h>
#define Size(t) (t ? t->sz : 0)
using namespace std;

const int maxn = 100000 + 5;

struct Treap {
  int val, pri, sz;
  Treap *l, *r, *fa;
  Treap(int v): val(v) {
    pri = rand();
    l = r = NULL;
    sz = 1;
    fa = NULL;
  }
  void pull() {
    if (l) l->fa = this;
    if (r) r->fa = this;
    sz = Size(l) + Size(r) + 1;
  }
} *t[maxn], *rt;

int N, M, T, x;

Treap* merge(Treap*, Treap*);
void split(Treap*, int, Treap*&, Treap*&);
int find(int);
void clear(Treap*&);
void print(Treap*);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T;
  while (T--) {
    cin >> N >> M;
    clear(rt); rt = NULL;
    for (int i = 1; i <= N; ++i) t[i] = NULL, t[i] = new Treap(i);
    for (int i = 1; i <= N; ++i) rt = merge(rt, t[i]);
    while (M--) {
      // print(rt); cout << '\n';
      cin >> x;
      int k = find(x);
      if (M) cout << k - 1 << ' ';
      else cout << k - 1 << '\n';
      Treap *a, *b, *c, *d;
      split(rt, k, a, b);
      split(a, k - 1, c, d);
      rt = merge(merge(d, c), b);
    }
  }
  return 0;
}

Treap* merge(Treap* a, Treap* b) {
  if (!a || !b) return a ? a : b;
  if (a->pri > b->pri) {
    a->r = merge(a->r, b);
    a->pull();
    return a;
  } else {
    b->l = merge(a, b->l);
    b->pull();
    return b;
  }
}

void split(Treap* u, int sz, Treap*& a, Treap*& b) {
  if (!u) { a = b = NULL; return; }
  if (Size(u->l) + 1 <= sz) {
    a = u;
    split(u->r, sz - Size(u->l) - 1, a->r, b);
    a->pull();
  } else {
    b = u;
    split(u->l, sz, a, b->l);
    b->pull();
  }
}

int find(int x) {
  Treap* u = t[x];
  if (u == rt) return Size(u->l) + 1;
  int ret = 0;
  bool add = true;
  while (u) {
    if (add) ret += Size(u->l) + 1;
    if (u->fa && u->fa->r == u) add = true;
    if (u->fa && u->fa->l == u) add = false;
    u = u->fa;
  }
  return ret;
}

void clear(Treap*& u) {
  if (!u) return;
  clear(u->l); clear(u->r);
  delete u; u = NULL;
}

void print(Treap* u) {
  if (!u) return;
  print(u->l);
  cout << u->val << ' ';
  print(u->r);
}
