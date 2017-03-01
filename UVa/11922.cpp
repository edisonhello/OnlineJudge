#include <bits/stdc++.h>
#define Size(t) (t ? t->sz : 0)
using namespace std;

struct Treap {
  int val, pri, sz;
  bool tag;
  Treap *l, *r;
  Treap(int v): val(v) {
    pri = rand();
    sz = 1;
    l = r = NULL;
    tag = false;
  }
  void pull() { sz = 1 + Size(l) + Size(r); }
  void push() {
    if (!tag) return;
    if (l) l->tag = !l->tag;
    if (r) r->tag = !r->tag;
    swap(l, r);
    tag = false;
  }
} *root;

int n, m;

Treap* merge(Treap*, Treap*);
void split(Treap*, int, Treap*&, Treap*&);
void print(Treap*);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m;
  root = NULL;
  for (int i = 1; i <= n; ++i) root = merge(root, new Treap(i));
  while (m--) {
    int L, R; cin >> L >> R;
    Treap *a, *b, *c, *d;
    split(root, L - 1, a, b); split(b, R - L + 1, c, d);
    c->tag = !c->tag;
    root = merge(merge(a, d), c);
  }
  print(root);
  return 0;
}

Treap* merge(Treap* a, Treap* b) {
  if (!a || !b) return a ? a : b;
  if (a->pri > b->pri) {
    a->push();
    a->r = merge(a->r, b);
    a->pull();
    return a;
  } else {
    b->push();
    b->l = merge(a, b->l);
    b->pull();
    return b;
  }
}

void split(Treap* t, int sz, Treap*& a, Treap*& b) {
  if (!t) { a = b = nullptr; return; }
  t->push();
  if (Size(t->l) + 1 <= sz) {
    a = t;
    split(t->r, sz - Size(t->l) - 1, a->r, b);
    a->pull();
  } else {
    b = t;
    split(t->l, sz, a, b->l);
    b->pull();
  }
}

void print(Treap* t) {
  t->push();
  if (t->l) print(t->l);
  cout << t->val << '\n';
  if (t->r) print(t->r);
}
