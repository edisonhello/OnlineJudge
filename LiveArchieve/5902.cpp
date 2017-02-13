#include <bits/stdc++.h>
#define Size(t) (t ? t->sz : 0)
using namespace std;

const int maxn = 100000 + 5;

struct Treap {
  int val, pri, sz;
  Treap *l, *r;
  Treap(int v): val(v) {
    pri = rand();
    l = r = NULL;
    sz = 1;
  }
} *tp[maxn], *root;

int T, N, M, fa[maxn];

void Init();
void clear(Treap*&);
Treap* merge(Treap*, Treap*);
void pull(Treap*);
void split(Treap*, int, Treap*&, Treap*&);
int find(Treap*, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T; while (T--) {
    Init();
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) tp[i] = new Treap(i);
    for (int i = 1; i <= N; ++i) root = merge(root, tp[i]);
    while (M--) {
      int A; cin >> A;
      int k = find(root, A);
      cout << k << ' ';
      Treap *a, *b, *c, *d;
      split(root, k + 1, a, b);
      split(a, k, c, d);
      root = merge(merge(d, c), b);
    }
    cout << '\n';
  }
  return 0;
}

void Init() {
  for (int i = 1; i <= N; ++i) clear(tp[i]);
  memset(fa, 0, sizeof(fa));
  root = NULL;
}

void clear(Treap*& t) {
  if (!t) return;
  clear(t->l); clear(t->r);
  delete t;
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

void pull(Treap* t) {
  if (!t) return;
  if (t->l) fa[t->l->val] = t->val;
  if (t->r) fa[t->r->val] = t->val;
  t->sz = Size(t->l) + Size(t->r) + 1;
}

void split(Treap* t, int sz, Treap*& a, Treap*& b) {
  if (!t) { a = b = NULL; return; }
  if (Size(t->l) + 1 <= sz) {
    a = t;
    split(t->r, sz - Size(t->l) - 1, a->r, b);
    pull(a);
  } else {
    b = t;
    split(t->l, sz, a, b->l);
    pull(b);
  }
}

int find(Treap* t, int x) {
  Treap* u = tp[x];
  int k = 0;
  while (true) {
    if (fa[u->val] && tp[fa[u->val]]->r->val == u->val) k += Size(u->l) + 1;
    if (fa[u->val]) u = tp[fa[u->val]];
    else break;
  }
  return k;
}
