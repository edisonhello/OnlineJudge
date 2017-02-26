#include <bits/stdc++.h>
#define lowbit(x) (x & -x)
using namespace std;

const int maxn = 50000 + 5, maxq = 10000 + 5;

struct Seg {
  Seg *l, *r;
  int cnt;
  Seg() {
    cnt = 0;
    l = NULL; r = NULL;
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
} *BIT[maxn], *top, mem[4000005];

struct Query { int tp, a, b, c; } q[maxq];
int T, N, Q, A[maxn];
vector<int> v;

void build(Seg*&, int, int);
void add(int, int, int);
Seg* modify(Seg*, int, int, int, int);
vector<Seg*> sum(int);
int query(vector<Seg*>&, vector<Seg*>&, int, int, int);
int leftSum(const vector<Seg*>&);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T; while (T--) {
    v.clear(); top = mem;
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) cin >> A[i], v.push_back(A[i]);
    for (int i = 0; i < Q; ++i) {
      cin >> q[i].tp;
      if (q[i].tp == 1) cin >> q[i].a >> q[i].b >> q[i].c;
      if (q[i].tp == 2) cin >> q[i].a >> q[i].b, v.push_back(q[i].b);
      if (q[i].tp == 3) cin >> q[i].a >> q[i].b;
    }
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
    build(BIT[0], 1, v.size());
    for (int i = 1; i <= N; ++i) BIT[i] = BIT[0];
    for (int i = 1; i <= N; ++i) {
      int ind = lower_bound(v.begin(), v.end(), A[i]) - v.begin() + 1;
      add(i, ind, 1);
    }
    for (int i = 0; i < Q; ++i) {
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
  if (L == R) { t->cnt = 0; return; }
  int M = (L + R) >> 1;
  build(t->l, L, M); build(t->r, M + 1, R);
}

void add(int x, int val, int delta) {
  while (x <= N) {
    BIT[x] = modify(BIT[x], 1, v.size(), val, delta);
    x += lowbit(x);
  }
}

Seg* modify(Seg* t, int L, int R, int x, int v) {
  Seg* ret = new(top++) Seg(t);
  if (L == R) return ret->cnt += v, ret;
  int M = (L + R) >> 1;
  if (x <= M) ret->l = modify(t->l, L, M, x, v);
  else ret->r = modify(t->r, M + 1, R, x, v);
  return ret;
}

vector<Seg*> sum(int x) {
  vector<Seg*> ret;
  Seg* z; build(z, 1, v.size());
  ret.push_back(z);
  while (x) {
    ret.push_back(BIT[x]);
    x -= lowbit(x);
  }
  return ret;
}

int query(vector<Seg*>& l, vector<Seg*>& r, int L, int R, int k) {
  if (L == R) return L;
  int ans = leftSum(r) - leftSum(l);
  int M = (L + R) >> 1;
  if (ans > k) {
    for (auto& i : l) i = i->l;
    for (auto& i : r) i = i->l;
    return query(l, r, L, M, k);
  } else {
    for (auto& i : l) i = i->r;
    for (auto& i : r) i = i->r;
    return query(l, r, M + 1, R, k - ans);
  }
}

int leftSum(const vector<Seg*>& vec) {
  int ret = 0;
  for (auto i : vec) ret += i->l->cnt;
  return ret;
}
