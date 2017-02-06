#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;

struct Treap {
  int val, pri, sz;
  Treap *l, *r;
  Treap(int v): val(v) {
    pri = rand();
    sz = 1;
    l = r = NULL;
  }
}* t[maxn];

int N, M, A[maxn], cycle, ans, a, b, fa[maxn];
bool v[maxn];

inline int Size(Treap* t) { return t ? t->sz : 0; }
void DFS(int, int);
void build(int, int);
Treap* merge(Treap*, Treap*);
void split(Treap*, int, Treap*&, Treap*&);
void pull(Treap*);
int F(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) cin >> A[i];
  for (int i = 1; i <= N; ++i) t[i] = new Treap(i);
  for (int i = 1; i <= N; ++i) if (!v[i]) cycle++, DFS(i, i);
  ans = N - cycle;
  cout << ans << '\n';
  while (M--) {
    cin >> a >> b;
    a = F(a), b = F(b);
    if (a == b) {
      --ans;

    } else {
      ++ans;
    }
    cout << ans << '\n';
  }
  return 0;
}

void DFS(int st, int x) {
  v[x] = true;
  if (v[A[x]]) return;
  t[st] = merge(t[st], t[A[x]]), DFS(st, A[x]);
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

void pull(Treap* t) {
  if (!t) return;
  t->sz = Size(t->l) + Size(t->r) + 1;
  if (t->l) fa[t->l->val] = t->val;
  if (t->r) fa[t->r->val] = t->val;
}

int F(int x) {
  return fa[x] ? F(fa[x]) : x;
}
