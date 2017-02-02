#include <bits/stdc++.h>
using namespace std;

struct Treap {
  int val, sz, pri;
  Treap *l, *r;
  Treap(int v): val(v) {
    pri = rand();
    l = r = NULL;
    sz = 1;
  }
} *root;

const int maxn = 1000000 + 5;
int N, a[maxn], b[maxn], bridge[maxn];
Treap* merge(Treap*, Treap*);
void split(Treap*, int, Treap*&, Treap*&);
void pull(Treap*);
int Size(Treap*);
void insert(Treap*&, int);
int Small(Treap*, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> a[i], b[N - i - 1] = a[i];
  fill(bridge, bridge + maxn, INT_MAX);
  for (int i = 0; i < N; ++i) {
    insert(root, a[i]);
    int smaller = Small(root, a[i] - 1);
    bridge[a[i]] = min(bridge[a[i]], kth(root, ))
  }
  return 0;
}

Treap* merge(Treap* a, Treap* b) {
  if (!a || !b) return a ? a : b;
  if (a->pri > b->pri) {
    a->r = merge(a->r, b);
    pull(a);
    return a;
  } else {
    b->l = merge(a, b->l);
    pull(b);
    return b;
  }
}

void split(Treap* t, int k, Treap*& a, Treap*& b) {
  if (!t) { a = b = nullptr; return; }
  if (t->val <= k) {
    a = t;
    split(t->r, k, a->r, b);
    pull(a);
  } else {
    b = t;
    split(t->l, k, a, b->l);
    pull(b);
  }
}

void pull(Treap* t) {
  if (!t) return;
  t->sz = Size(t->l) + Size(t->r) + 1;
}

int Size(Treap* t) {
  return t ? t->sz : 0;
}

void insert(Treap*& t, int v) {
  Treap *a, *b;
  split(t, v - 1, a, b);
  t = merge(merge(a, new Treap(v)), b);
}

int Small(Treap* t, int v) {
  if (!t) return 0;
  if (t->val > v) return Small(t->l, v);
  else return Size(t->l) + Small(t->r, v);
}
