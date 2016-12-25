#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <fstream>
using namespace std;

const int maxn = 20000 + 5;
const int maxq = 1000000 + 5;
const int maxm = 60000 + 5;
int T, N, M, D[maxn], u, v, a, b, q, djs[maxn], cnt, kase;
long long sum;
char c;
bool col[maxn];

struct Treap {
  int val, pri, sz;
  Treap *l, *r;
  Treap(int v): val(v) {
    pri = rand();
    sz = 1;
    l = r = NULL;
  }
  inline int Lsz() { return l ? l->sz : 0; }
  inline int Rsz() { return r ? r->sz : 0; }
} *root[maxn] = {0};

struct Query {
  int a, b;
  char c;
} Q[maxq];

struct Edge {
  int st, ed;
} E[maxm];

int F(int x) { return x == djs[x] ? x : djs[x] = F(djs[x]); }

void Connect(int);
Treap* merge(Treap*, Treap*);
void pull(Treap*);
void del(Treap*&, int);
void insert(Treap*&, int);
void split(Treap*, int, Treap*&, Treap*&);
int kth(Treap*, int);
void connect(Treap*&, Treap*&);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  while (cin >> N >> M, (N || M)) {
    memset(col, false, sizeof(col)); q = 0;
    for (int i = 1; i <= N; ++i) root[i] = NULL;
    for (int i = 1; i <= N; ++i) djs[i] = i;
    for (int i = 1; i <= N; ++i) cin >> D[i];
    for (int i = 1; i <= M; ++i) cin >> u >> v, E[i] = (Edge){ u, v };
    while (cin >> c) {
      if (c == 'Q') cin >> a >> b;
      if (c == 'C') cin >> a >> b, swap(D[a], b);
      if (c == 'D') cin >> a, col[a] = true;
      if (c == 'E') break;
      Q[q++] = (Query){ a, b, c };
    }
    for (int i = 1; i <= N; ++i) root[i] = new Treap(D[i]);
    for (int i = 1; i <= M; ++i) if (!col[i]) Connect(i);
    sum = 0; cnt = 0;
    while (q--) {
      if (Q[q].c == 'D') Connect(Q[q].a);
      if (Q[q].c == 'C') {
        del(root[F(Q[q].a)], D[Q[q].a]);
        D[Q[q].a] = Q[q].b;
        insert(root[F(Q[q].a)], D[Q[q].a]);
      }
      if (Q[q].c == 'Q') cnt++, sum += kth(root[F(Q[q].a)], Q[q].b);
    }
    cout << "Case " << ++kase << ": " << fixed << setprecision(6) << (double)sum * 1.0 / cnt << '\n';
  }
  return 0;
}

void Connect(int id) {
  int x = F(E[id].st), y = F(E[id].ed);
  if (x == y) return;
  if (root[x] && root[y] && root[x]->sz < root[y]->sz) swap(x, y);
  connect(root[x], root[y]);
  djs[y] = x;
  delete root[y];
}

void connect(Treap*& a, Treap*& b) {
  if (b->l) connect(a, b->l);
  if (b->r) connect(a, b->r);
  insert(a, b->val);;
  delete b;
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

void pull(Treap* treap) {
  if (!treap) return;
  treap->sz = treap->Lsz() + treap->Rsz() + 1;
}

void del(Treap*& treap, int val) {
  Treap *a, *b, *c, *d;
  split(treap, val, a, b);
  split(a, val - 1, c, d);
  treap = merge(c, b);
}

void split(Treap* treap, int v, Treap*& a, Treap*& b) {
  if (!treap) { a = b = NULL; return; }
  if (treap->val <= v) {
    a = treap;
    split(treap->r, v, a->r, b);
    pull(a);
  } else {
    b = treap;
    split(treap->l, v, a, b->l);
    pull(b);
  }
}

void insert(Treap*& treap, int val) {
  Treap *a, *b, *c;
  split(treap, val, a, b);
  c = merge(a, new Treap(val));
  treap = merge(c, b);
}

int kth(Treap* treap, int k) {
  if (!treap || k <= 0 || k > treap->sz) return 0;
  if (treap->Rsz() + 1 == k) return treap->val;
  if (treap->Rsz() + 1 > k) return kth(treap->r, k);
  else return kth(treap->l, k - treap->Rsz() - 1);
}
