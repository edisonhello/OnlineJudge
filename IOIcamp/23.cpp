#include <bits/stdc++.h>
#define Lc(id) (id << 1)
#define Rc(id) (id << 1 | 1)
using namespace std;

const int maxn = 100000 + 5;
struct Seg { long long sum, tag; } seg[maxn << 2];
int T, N, Q, A[maxn], l, r, d;
string s;

void build(int, int, int);
void modify(int, int, int, int, int, int);
long long query(int, int, int, int, int);
void push(int, int, int);
void pull(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T; while (T--) {
    cin >> N >> Q;
    memset(seg, 0, sizeof(seg));
    for (int i = 1; i <= N; ++i) cin >> A[i];
    build(1, 1, N);
    while (Q--) {
      cin >> s;
      if (s == "add") cin >> l >> r >> d, modify(1, 1, N, l, r, d);
      if (s == "query") cin >> l >> r, cout << query(1, 1, N, l, r) << '\n';
    }
  }
  return 0;
}

void build(int id, int L, int R) {
  if (L == R) {
    seg[id].sum = A[L], seg[id].tag = 0;
    return;
  }
  int M = (L + R) >> 1;
  build(Lc(id), L, M); build(Rc(id), M + 1, R);
  pull(id);
}

void modify(int id, int L, int R, int l, int r, int d) {
  push(id, L, R);
  if (L > r || l > R) return;
  if (L >= l && R <= r) {
    seg[id].sum += (R - L + 1) * d;
    seg[id].tag += d;
    return;
  }
  int M = (L + R) >> 1;
  modify(Lc(id), L, M, l, r, d); modify(Rc(id), M + 1, R, l, r, d);
  pull(id);
}

long long query(int id, int L, int R, int l, int r) {
  push(id, L, R);
  if (L > r || l > R) return 0;
  if (L >= l && R <= r) return seg[id].sum;
  int M = (L + R) >> 1;
  return query(Lc(id), L, M, l, r) + query(Rc(id), M + 1, R, l, r);
}

void push(int id, int L, int R) {
  if (L == R) return;
  if (!seg[id].tag) return;
  int M = (L + R) >> 1;
  seg[Lc(id)].sum += (M - L + 1) * seg[id].tag; seg[Lc(id)].tag += seg[id].tag;
  seg[Rc(id)].sum += (R - M) * seg[id].tag; seg[Rc(id)].tag += seg[id].tag;
  seg[id].tag = 0;
}

void pull(int id) {
  seg[id].sum = seg[Lc(id)].sum + seg[Rc(id)].sum;
}
