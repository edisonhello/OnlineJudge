#include <bits/stdc++.h>
#define Lc(id) (id << 1)
#define Rc(id) (id << 1 | 1)
using namespace std;

const int maxn = 100000 + 5;
struct Seg { int sum; bool tag; } seg[maxn << 2];
struct Event { int a, b, c; } e[maxn];
int N;

void Init();
int query(int, int, int, int, int);
void modify(int, int, int, int, int);
void push(int, int, int);
void pull(int);
int bs(int, int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  while (cin >> N, N) {
    Init();
    for (int i = 0; i < N; ++i) cin >> e[i].a >> e[i].b >> e[i].c, e[i].b--;
    sort(e, e + N, [](const Event& e1, const Event& e2) -> bool {
      return e1.b == e2.b ? e1.c == e2.c ? e1.a < e2.a : e1.c > e2.c : e1.b < e2.b;
    });
    for (int i = 0; i < N; ++i) {
      int q = query(1, 0, maxn, e[i].a, e[i].b);
      if (e[i].c - q <= 0) continue;
      int x = bs(e[i].a, e[i].b, e[i].c - q);
      modify(1, 0, maxn, x, e[i].b);
    }
    cout << query(1, 0, maxn, 0, maxn) << '\n';
  }
  return 0;
}

void Init() {
  memset(seg, 0, sizeof(seg));
  memset(e, 0, sizeof(e));
}

int query(int id, int L, int R, int l, int r) {
  if (L < R) push(id, L, R);
  if (L > r || l > R) return 0;
  if (L >= l && R <= r) return seg[id].sum;
  int M = (L + R) >> 1;
  return query(Lc(id), L, M, l, r) + query(Rc(id), M + 1, R, l, r);
}

void modify(int id, int L, int R, int l, int r) {
  if (L < R) push(id, L, R);
  if (L > r || l > R) return;
  if (L >= l && R <= r) {
    seg[id].sum = R - L + 1; seg[id].tag  = true;
    if (L < R) push(id, L, R);
    return;
  }
  int M = (L + R) >> 1;
  modify(Lc(id), L, M, l, r); modify(Rc(id), M + 1, R, l, r);
  pull(id);
}

void pull(int id) {
  seg[id].sum = seg[Lc(id)].sum + seg[Rc(id)].sum;
}

void push(int id, int L, int R) {
  if (!seg[id].tag) return;
  int M = (L + R) >> 1;
  seg[Lc(id)].sum = M - L + 1; seg[Lc(id)].tag = true;
  seg[Rc(id)].sum = R - M; seg[Rc(id)].tag = true;
  seg[id].tag = false;
}

int bs(int a, int b, int c) {
  int L = a, R = b;
  while (L < R) {
    int M = (L + R) >> 1;
    if (b - M + 1 - query(1, 0, maxn, M, b) > c) L = M + 1;
    else R = M;
  }
  return L;
}
