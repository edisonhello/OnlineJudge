#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define getchar getchar_unlocked
using namespace std;

const int maxn = 20000 + 5;
const int maxm = 60000 + 5;
const int maxq = 200000 + 5;

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
  int val;
  int sz, pri;
  Treap *l, *r;
  Treap(int v): l(NULL), r(NULL) {
    val = v;
    sz = 1;
    pri = rand();
  }
} *treap[maxn];

inline int size(Treap* treap) {
  return treap ? treap->sz : 0;
}

struct Query {
  char c;
  int a, b;
} Q[maxq];

struct Edge {
  int st, ed;
} E[maxm];

int N, M, djs[maxn], cnt, kase, a, b, D[maxn];
long long sum;
bool col[maxm];
char c;

Treap* merge(Treap*, Treap*);
void split(Treap*, int, Treap*&, Treap*&);
inline void Connect(int);
inline void insert(Treap*&, int);
inline void remove(Treap*&, int);
void connect(Treap*&, Treap*&);
int F(int);
int kth(Treap*, int);
inline void pull(Treap*);

int main() {
  srand(7122);
  while (rit(N, M), (N || M)) {
    memset(col, 0, sizeof(col));
    for (int i = 0; i < N; ++i) djs[i] = i;
    for (int i = 0; i < N; ++i) rit(D[i]);
    for (int i = 0; i < M; ++i) rit(E[i].st, E[i].ed);
    int q = 0;
    while (c = getchar()) {
      if (c == 'Q') rit(a, b);
      if (c == 'C') rit(a, b), swap(D[a], b);
      if (c == 'D') rit(a), col[a] = true;
      if (c == 'E') break;
      Q[q++] = (Query){ c, a, b };
    }
    for (int i = 0; i < N; ++i) treap[i] = new Treap(D[i]);
    for (int i = 0; i < M; ++i) if (!col[i]) Connect(i);
    sum = 0; cnt = 0;
    while (q--) {
      if (Q[q].c == 'C') {
        int a = F(Q[q].a);
        remove(treap[a], D[Q[q].a]);
        D[Q[q].a] = Q[q].b;
        insert(treap[a], D[Q[q].a]);
      }
      if (Q[q].c == 'D') Connect(Q[q].a);
      if (Q[q].c == 'Q') sum += kth(treap[F(Q[q].a)], Q[q].b), cnt++;
    }
    printf("Case %d: %.6lf\n", ++kase, (double)sum * 1.0 / cnt);
  }
  return 0;
}

int F(int x) { return x == djs[x] ? x : djs[x] = F(djs[x]); }

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

void split(Treap* treap, int k, Treap*& a, Treap*& b) {
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
    return;
  }
}

inline void pull(Treap* treap) {
  if (!treap) return;
  treap->sz = size(treap->l) + size(treap->r) + 1;
}

inline void Connect(int id) {
  int x = F(E[id].st), y = F(E[id].ed);
  if (x == y) return;
  if (size(treap[x]) < size(treap[y])) swap(x, y);
  connect(treap[x], treap[y]);
  djs[y] = x;
}

void connect(Treap*& a, Treap*& b) {
  if (b->l) connect(a, b->l);
  if (b->r) connect(a, b->r);
  insert(a, b->val);
  delete b;
}

inline void insert(Treap*& treap, int v) {
  Treap *a, *b;
  split(treap, v, a, b);
  treap = merge(merge(a, new Treap(v)), b);
}

inline void remove(Treap*& treap, int v) {
  Treap *a, *b, *c, *d;
  split(treap, v - 1, a, treap);
  split(treap, v, treap, b);
  c = treap;
  treap = merge(a, merge(treap->l, merge(treap->r, b)));
  delete c;
}

int kth(Treap* treap, int k) {
  if (!treap || k <= 0 || k > size(treap)) return 0;
  if (size(treap->r) + 1 == k) return treap->val;
  if (size(treap->r) + 1 > k) return kth(treap->r, k);
  else return kth(treap->l, k - size(treap->r) - 1);
}
