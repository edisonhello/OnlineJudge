#include <cstdio>
#include <vector>
#include <algorithm>
#define root 1
#define Lc(id) (id) << 1
#define Rc(id) (id) << 1 | 1
#define getchar getchar_unlocked
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

const int maxn = 50000 + 5;
const int maxq = 10000 + 5;
int x;

inline unsigned ran() {
  return x = x * 0xefaced + 1;
}

struct Treap {
  Treap *l, *r;
  int v, cnt, sz, sm, pri;
  Treap(int v): v(v), l(NULL), r(NULL) {
    sz = 1;
    cnt = 1;
    sm = 1;
    pri = ran();
  }
} *Seg[maxn << 2];

struct Query {
  char t;
  int a, b, c;
} Q[maxq];

int T, N, M, A[maxn], a, b, c;
char t;
vector<int> v;

void build(int, int, int);
int query(int, int, int, int, int, int);
void modify(int, int, int, int, int);

inline void pull(Treap*);
inline int size(Treap*);
inline int sum(Treap*);
void insert(Treap*&, int);
void remove(Treap*&, int);
int kth(Treap*, int);
void clear(Treap*&);
void rotate(Treap*&, int);
void Rotate(Treap*&);
void Remove(Treap*&);

int main() {
  rit(T);
  while (T--) {
    rit(N, M);
    v.clear();
    for (int i = 0; i < N; ++i) rit(A[i]), v.push_back(A[i]);
    build(root, 0, N - 1);
    for (int i = 0; i < M; ++i) {
      t = getchar();
      if (t == '1') rit(a, b, c), a--, b--;
      if (t == '2') rit(a, b), a--, v.push_back(b);
      if (t == '3') rit(a, b), a--;
      Q[i] = (Query){ t, a, b, c };
    }
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 0; i < M; ++i) {
      if (Q[i].t == '1') {
        int lb = 0, ub = v.size();
        while (lb < ub) {
          int mid = (lb + ub) >> 1;
        int res = query(root, 0, N - 1, Q[i].a, Q[i].b, v[mid]);
          if (res >= Q[i].c) ub = mid;
          else lb = mid + 1;
        }
        printf("%d\n", v[ub]);
      }
      if (Q[i].t == '2') modify(root, 0, N - 1, Q[i].a, Q[i].b), A[Q[i].a] = Q[i].b;
      if (Q[i].t == '3') puts("7122");
    }
  }
  return 0;
}

void build(int id, int L, int R) {
  clear(Seg[id]);
  for (int i = L; i <= R; ++i) insert(Seg[id], A[i]);
  if (L == R) return;
  int M = (L + R) >> 1;
  build(Lc(id), L, M);
  build(Rc(id), M + 1, R);
}


int query(int id, int L, int R, int l, int r, int k) {
  if (L > r || l > R) return 0;
  if (L >= l && R <= r) return kth(Seg[id], k);
  int M = (L + R) >> 1;
  return query(Lc(id), L, M, l, r, k) + query(Rc(id), M + 1, R, l, r, k);
}

void modify(int id, int L, int R, int x, int v) {
  remove(Seg[id], A[x]); insert(Seg[id], v);
  if (L == R) return;
  int M = (L + R) >> 1;
  if (x <= M) modify(Lc(id), L, M, x, v);
  else modify(Rc(id), M + 1, R, x, v);
}

inline void pull(Treap* treap) {
  if (!treap) return;
  treap->sz = size(treap->l) + size(treap->r) + 1;
  treap->sm = sum(treap->l) + treap->cnt + sum(treap->r);
}

inline int size(Treap* treap) {
  return treap ? treap->sz : 0;
}

inline int sum(Treap* treap) {
  return treap ? treap->sm : 0;
}

void insert(Treap*& treap, int v) {
  if (!treap) { treap = new Treap(v); return; }
  if (treap->v == v) { treap->cnt++; pull(treap); return; }
  insert((v < treap->v ? treap->l : treap->r), v);
  pull(treap);
  Rotate(treap);
}
int kth(Treap* treap, int k) {
  if (!treap) return 0;
  if (treap->v <= k) return sum(treap->l) + treap->cnt + kth(treap->r, k);
  else return kth(treap->l, k);
}

void remove(Treap*& treap, int v) {
  if (treap->v == v) {
    treap->cnt--;
    pull(treap);
    if (treap->cnt == 0) Remove(treap);
    return;
  }
  remove((v < treap->v) ? treap->l : treap->r, v);
  pull(treap);
}

void clear(Treap*& treap) {
  if (!treap) return;
  clear(treap->l);
  clear(treap->r);
  delete treap;
  treap = NULL;
}

void rotate(Treap*& treap, int d) {
  Treap* u = treap;
  treap = (d ? treap->r : treap->l);
  (d ? u->r : u->l) = (d ? treap->l : treap->r);
  (d ? treap->l : treap->r) = u;
  pull(u); pull(treap);
}

void Rotate(Treap*& treap) {
  if (size(treap->l) > size(treap->r)) rotate(treap, 0);
  else if (size(treap->r) > size(treap->l)) rotate(treap, 1);
}

void Remove(Treap*& treap) {
  if (!treap->l || !treap->r) {
    Treap* u = treap;
    treap = (treap->l ? treap->l : treap->r);
    delete u;
    return;
  }
  int d = size(treap->l) > size(treap->r) ? 0 : 1;
  rotate(treap, d);
  Remove(d ? treap->l : treap->r);

}
