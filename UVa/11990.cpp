#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 5;
int n, m, a[maxn], pos[maxn];

struct Seg {
  static Seg mem[4000005];
  static Seg* top;
  int cnt, L, R;
  Seg *l, *r;
  Seg(): cnt(0), l(NULL), r(NULL) {}
  Seg(int L, int R) {
    this->L = L; this->R = R;
    if (L == R) { cnt = 0; return; }
    int M = (L + R) >> 1;
    l = new(Seg::top++) Seg(L, M); r = new(Seg::top++) Seg(M + 1, R);
    pull();
  }
  Seg(Seg* t) {
    cnt = t->cnt;
    l = t->l;
    r = t->r;
    L = t->L;
    R = t->R;
  }
  void pull() {
    cnt = 0;
    if (l) cnt += l->cnt;
    if (r) cnt += r->cnt;
  }
  Seg* modify(int x, int v) {
    Seg* ret = new(Seg::top++) Seg(this);
    if (L == R) { ret->cnt += v; return ret; }
    int M = (L + R) >> 1;
    if (x <= M) ret->l = l->modify(x, v);
    else ret->r = r->modify(x, v);
    ret->pull();
    return ret;
  }
  int query(int L, int R) {
    if (this->L > R || L > this->R) return 0;
    if (this->L >= L && this->R <= R) return cnt;
    return l->query(L, R) + r->query(L, R);
  }
};

struct BIT {
  #define lowbit(x) (x & -x)
  Seg *seg[maxn];
  void init() {
    Seg::top = Seg::mem;
    seg[0] = new Seg(1, n);
    for (int i = 1; i <= n; ++i) seg[i] = seg[0];
  }
  void add(int id, int x, int v) {
    for (int i = id; i <= n; i += lowbit(i)) seg[i] = seg[i]->modify(x, v);
  }
  vector<Seg*> sum(int id) {
    vector<Seg*> ret;
    ret.push_back(new Seg(1, n));
    for (int i = id; i; i -= lowbit(i)) ret.push_back(seg[i]);
    return ret;
  }
  #undef lowbit
} bit;

int Inverse();
void print(Seg*);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> n >> m) {
    for (int i = 1; i <= n; ++i) cin >> a[i], pos[a[i]] = i;
    bit.init();
    for (int i = 1; i <= n; ++i) bit.add(i, a[i], 1);
    int inv = Inverse();
    while (m--) {
      cout << inv << '\n';
      int d, ans = 0; cin >> d;
      vector<Seg*> res1 = bit.sum(pos[d]), res2 = bit.sum(n);
      for (Seg* t : res1) ans += t->query(d + 1, n);
      for (Seg* t : res2) ans += t->query(1, d - 1);
      for (Seg* t : res1) ans -= t->query(1, d - 1);
      // cout << "ans: " << ans << '\n';
      inv -= ans;
      bit.add(pos[d], d, -1);
    }
  }
  return 0;
}

int Inverse() {
  int fenwick[maxn], ret = 0;
  memset(fenwick, 0, sizeof(fenwick));
  auto add = [&fenwick](int x, int v) -> void {
    for (int i = x; i <= n; i += (i & -i)) fenwick[i] += v;
  };
  auto sum = [&fenwick](int x) -> int {
    int ret = 0;
    for (int i = x; i; i -= (i & -i)) ret += fenwick[i];
    return ret;
  };
  for (int i = 1; i <= n; ++i) {
    ret += i - 1 - sum(a[i]);
    add(a[i], 1);
  }
  return ret;
}

void print(Seg* t) {
  if (t->l) print(t->l);
  cout << "L=" << t->L << "  R=" << t->R << ": " << t->cnt << '\n';
  if (t->r) print(t->r);
}
