#include <bits/stdc++.h>
#define Size(t) (t ? t->sz : 0)
#define Sum(t) (t ? t->sum : 0)
using namespace std;

typedef long long LL;

struct Treap {
  int val, pri, sz;
  long long sum;
  Treap *l, *r;
  Treap(int v): val(v) {
    l = r = NULL;
    pri = rand();
    sz = 1;
    sum = v;
  }
} *t, *s;

int K, N, S, T;
long long ans;
char P, Q;
vector<pair<int, int>> v;

bool cmp(const pair<int, int>&, const pair<int, int>&);
inline void f();
inline void g();
Treap* merge(Treap*, Treap*);
void split(Treap*, int, Treap*&, Treap*&);
inline void pull(Treap*);
inline void insert(Treap*&, int);
inline void remove(Treap*&, int);
int kth(Treap*, int);
inline pair<long long, int> cal(Treap*, int);

int main() {
  srand(7122);
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  t = NULL; s = NULL;
  cin >> K >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> P >> S >> Q >> T;
    if (P == Q) { ans += abs(S - T); continue; }
    v.push_back(minmax(S, T));
  }
  if (v.empty()) return cout << ans << '\n', 0;
  if (K == 1) g();
  if (K == 2) f();
  return 0;
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
  return a.first + a.second < b.first + b.second;
}

inline void f() {
  sort(v.begin(), v.end(), cmp);
  for (auto i : v) insert(s, i.first), insert(s, i.second);
  long long Min = LLONG_MAX;
  int a = 0, b = 0, s11 = 0, b11 = 0, s21 = 0, b21 = 0;
  long long s1 = 0, b1 = 0, s2 = 0, b2 = 0;
  if (Size(t)) {
    a = kth(t, Size(t) / 2 + 1);
    tie(s1, s11) = cal(t, a), b1 = Sum(t) - s1, b11 = Size(t) - s11;
  }
  if (Size(s)) {
    b = kth(s, Size(s) / 2 + 1);
    tie(s2, s21) = cal(s, b); b2 = Sum(s) - s2, b21 = Size(s) - s21;
  }
  Min = min(Min, (LL)b1 - (LL)s1 + (LL)b2 - (LL)s2 - (LL)(b11 - s11) * (LL)a - (LL)(b21 - s21) * (LL)b);
  for (int i = 0; i < v.size(); ++i) {
    insert(t, v[i].first); insert(t, v[i].second);
    remove(s, v[i].first); remove(s, v[i].second);
    int a = 0, b = 0, s11 = 0, b11 = 0, s21 = 0, b21 = 0;
    long long s1 = 0, b1 = 0, s2 = 0, b2 = 0;
    if (Size(t)) {
      a = kth(t, Size(t) / 2 + 1);
      tie(s1, s11) = cal(t, a), b1 = Sum(t) - s1, b11 = Size(t) - s11;
    }
    if (Size(s)) {
      b = kth(s, Size(s) / 2 + 1);
      tie(s2, s21) = cal(s, b); b2 = Sum(s) - s2, b21 = Size(s) - s21;
    }
    Min = min(Min, (LL)b1 - (LL)s1 + (LL)b2 - (LL)s2 - (LL)(b11 - s11) * (LL)a - (LL)(b21 - s21) * (LL)b);
  }
  cout << ans + Min + (LL)v.size() << '\n';
}

inline void g() {
  long long res = 0;
  vector<int> w;
  for (auto i : v) w.push_back(i.first), w.push_back(i.second);
  nth_element(w.begin(), w.begin() + w.size() / 2, w.end());
  for (auto i : v) res += abs(i.first - w[w.size() / 2]) + abs(i.second - w[w.size() / 2]);
  cout << ans + res + (int)v.size() << '\n';
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
  if (!t) { a = b = NULL; return; }
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

inline void pull(Treap* t) {
  if (!t) return;
  t->sz = Size(t->l) + Size(t->r) + 1;
  t->sum = Sum(t->l) + Sum(t->r) + t->val;
}

inline void insert(Treap*& t, int k) {
  Treap *a, *b;
  split(t, k - 1, a, b);
  t = merge(merge(a, new Treap(k)), b);
}

int kth(Treap* t, int k) {
  if (Size(t->l) + 1 == k) return t->val;
  if (Size(t->l) + 1 > k) return kth(t->l, k);
  else return kth(t->r, k - Size(t->l) - 1);
}

inline void remove(Treap*& t, int k) {
  Treap *a, *b, *c, *d;
  split(t, k - 1, a, b);
  split(b, k, c, d);
  t = merge(a, merge(merge(c->l, c->r), d));
  delete c;
}

inline pair<long long, int> cal(Treap* t, int k) {
  Treap *a, *b;
  split(t, k - 1, a, b);
  long long ret = Sum(a);
  int sz = Size(a);
  t = merge(a, b);
  return make_pair(ret, sz);
}
