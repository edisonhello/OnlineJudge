#include <bits/stdc++.h>
using namespace std;

struct Seg {
  Seg *lc, *rc;
  int sum, tag;
  Seg() {
    lc = NULL; rc = NULL;
  }
  Seg(int L, int R) {
    sum = 0; tag = -1;
    if (L == R) return;
    int M = (L + R) >> 1;
    lc = new Seg(L, M); rc = new Seg(M + 1, R);
  }
  ~Seg() {
    if (lc) delete lc, lc = NULL;
    if (rc) delete rc, rc = NULL;
  }
  #define Sum(t) (t ? t->sum : 0)
  void pull() {
    sum = Sum(lc) + Sum(rc);
  }
  #undef Sum
  void push(int L, int R) {
    if (tag == -1) return;
    if (L == R) return;
    int M = (L + R) >> 1;
    if (lc) lc->tag = tag, lc->sum = tag * (M - L + 1);
    if (rc) rc->tag = tag, rc->sum = tag * (R - M);
    tag = -1;
  }
  int query(int L, int R, int l, int r) {
    push(L, R);
    if (L > r || l > R) return 0;
    if (L >= l && R <= r) return sum;
    int M = (L + R) >> 1;
    return lc->query(L, M, l, r) + rc->query(M + 1, R, l, r);
  }
  void modify(int L, int R, int l, int r, int v) {
    push(L, R);
    if (L > r || l > R) return;
    if (L >= l && R <= r) {
      sum = (R - L + 1) * v;
      tag = v;
      return;
    }
    int M = (L + R) >> 1;
    lc->modify(L, M, l, r, v); rc->modify(M + 1, R, l, r, v);
    pull();
  }
} *segA, *segB;

const int maxn = 100000 + 5;
int na, nb, x, y;
struct Interval { int x, y; } a[maxn], b[maxn];
vector<int> va, vb;

void clear(Seg*& t) {
  if (!t) return;
  if (t->lc) clear(t->lc);
  if (t->rc) clear(t->rc);
  delete t; t = NULL;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> na >> nb) {
    segA = nullptr; segB = nullptr;
    va.clear(); vb.clear();
    for (int i = 0; i < na; ++i) cin >> a[i].x >> a[i].y, va.push_back(a[i].x), va.push_back(a[i].y);
    for (int i = 0; i < nb; ++i) cin >> b[i].x >> b[i].y, vb.push_back(b[i].x), vb.push_back(b[i].y);
    cin >> x >> y;
    va.push_back(x); va.push_back(y); vb.push_back(x); vb.push_back(y);
    sort(va.begin(), va.end()); va.resize(unique(va.begin(), va.end()) - va.begin());
    sort(vb.begin(), vb.end()); vb.resize(unique(vb.begin(), vb.end()) - vb.begin());
    segA = new Seg(0, va.size() - 1); segB = new Seg(0, vb.size() - 1);
    if (na > nb) swap(segA, segB), swap(va, vb), swap(a, b), swap(na, nb);
    int Xa = lower_bound(va.begin(), va.end(), x) - va.begin();
    int Ya = lower_bound(va.begin(), va.end(), y) - va.begin();
    int Xb = lower_bound(vb.begin(), vb.end(), x) - vb.begin();
    int Yb = lower_bound(vb.begin(), vb.end(), y) - vb.begin();
    int win = -1;
    for (int i = 0; i < na; ++i) {
      int La = lower_bound(va.begin(), va.end(), a[i].x) - va.begin();
      int Ra = lower_bound(va.begin(), va.end(), a[i].y) - va.begin();
      segA->modify(0, va.size() - 1, La, Ra, 1);
      if (segA->query(0, va.size() - 1, Xa, Ya) == Ya - Xa + 1) { win = 1; break; }
      int Lb = lower_bound(vb.begin(), vb.end(), b[i].x) - vb.begin();
      int Rb = lower_bound(vb.begin(), vb.end(), b[i].y) - vb.begin();
      segB->modify(0, vb.size() - 1, Lb, Rb, 1);
      if (segB->query(0, vb.size() - 1, Xb, Yb) == Yb - Xb + 1) { win = 0; break; }
    }
    if (win == -1) for (int i = na; i < nb; ++i) {
      int Lb = lower_bound(vb.begin(), vb.end(), b[i].x) - vb.begin();
      int Rb = lower_bound(vb.begin(), vb.end(), b[i].y) - vb.begin();
      segB->modify(0, vb.size() - 1, Lb, Rb, 1);
      if (segB->query(0, vb.size() - 1, Xb, Yb) == Yb - Xb + 1) { win = 0; break; }
    }
    if (win == 1) cout << "A WIN\n";
    else if (win == 0) cout << "B WIN\n";
    else cout << "TIE\n";
    // clear(segA); clear(segB);
    delete segA; delete segB;
    // segA = NULL; segB = NULL;
  }
  return 0;
}
