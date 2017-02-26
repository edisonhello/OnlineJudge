#include <bits/stdc++.h>
#define lowbit(x) (x & -x)
using namespace std;

const int maxn = 50000 + 5, maxq = 10000 + 5;
int T, N, M, A[maxn];
struct Query { int tp, a, b, c; } q[maxq];

struct Seg {
  int cnt;
  Seg *l, *r;
  Seg() {
    cnt = 0;
    l = r = NULL;
  }
  Seg(Seg* t) {
    cnt = t->cnt;
    l = t->l;
    r = t->r;
  }
  void pull() {
    cnt = 0;
    if (l) cnt += l->cnt;
    if (r) cnt += r->cnt;
  }
} *seg[maxn], *top, mem[4000005];

vector<int> v;
Seg* modify(Seg*, int, int, int, int);
void build(Seg*&, int, int);
int query(vector<Seg*>&, vector<Seg*>&, int, int, int);
void add(int, int, int);
inline int leftSum(const vector<Seg*>&);
vector<Seg*> sum(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T; while (T--) {
    top = mem;
    cin >> N >> M;
    v.clear();
    for (int i = 1; i <= N; ++i) cin >> A[i], v.push_back(A[i]);
    for (int i = 0; i < M; ++i) {
      int tp, a, b, c;
      cin >> tp;
      if (tp == 1) cin >> a >> b >> c;
      if (tp == 2) cin >> a >> b, v.push_back(b);
      if (tp == 3) cin >> a >> b;
      q[i] = (Query){ tp, a, b, c };
    }
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
    build(seg[0], 1, v.size());
    for (int i = 1; i <= N; ++i) seg[i] = seg[0];
    for (int i = 1; i <= N; ++i) {
      int ind = lower_bound(v.begin(), v.end(), A[i]) - v.begin() + 1;
      add(i, ind, 1);
    }
    for (int i = 0; i < M; ++i) {
      if (q[i].tp == 1) {
        vector<Seg*> r = sum(q[i].b);
        vector<Seg*> l = sum(q[i].a - 1);
        cout << v[query(l, r, 1, v.size(), q[i].c) - 1] << '\n';
      }
      if (q[i].tp == 2) {
        int ind = lower_bound(v.begin(), v.end(), A[q[i].a]) - v.begin() + 1;
        add(q[i].a, ind, -1);
        A[q[i].a] = q[i].b;
        ind = lower_bound(v.begin(), v.end(), A[q[i].a]) - v.begin() + 1;
        add(q[i].a, ind, 1);
      }
      if (q[i].tp == 3) cout << "7122\n";
    }
  }
  return 0;
}

void build(Seg*& t, int L, int R) {
  t = new(top++) Seg();
  if (L == R) {
    t->cnt = 0;
    return;
  }
  int M = (L + R) >> 1;
  build(t->l, L, M); build(t->r, M + 1, R);
  t->pull();
}

Seg* modify(Seg* t, int L, int R, int x, int v) {
  Seg* ret = new(top++) Seg(t);
  if (L == R) {
    ret->cnt += v;
    return ret;
  }
  int M = (L + R) >> 1;
  if (x <= M) ret->l = modify(t->l, L, M, x, v);
  else ret->r = modify(t->r, M + 1, R, x, v);
  ret->pull();
  return ret;
}

int query(vector<Seg*>& l, vector<Seg*>& r, int L, int R, int k) {
  if (L == R) return L;
  int M = (L + R) >> 1;
  int ans = leftSum(r) - leftSum(l);
  if (ans >= k) {
    for (auto& s : l) s = s->l;
    for (auto& s : r) s = s->l;
    return query(l, r, L, M, k);
  } else {
    for (auto& s : l) s = s->r;
    for (auto& s : r) s = s->r;
    return query(l, r, M + 1, R, k - ans);
  }
}

void add(int x, int val, int delta) {
  while (x <= N) {
    seg[x] = modify(seg[x], 1, v.size(), val, delta);
    x += lowbit(x);
  }
}

vector<Seg*> sum(int x) {
  vector<Seg*> ret;
  Seg* z;
  build(z, 1, v.size());
  ret.push_back(z);
  while (x) {
    ret.push_back(seg[x]);
    x -= lowbit(x);
  }
  return ret;
}

inline int leftSum(const vector<Seg*>& vec) {
  int ret = 0;
  for (auto i : vec) ret += i->l->cnt;
  return ret;
}
