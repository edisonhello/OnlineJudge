#include <iostream>
#include <cstring>
#define Lc(x) (x) << 1
#define Rc(x) ((x) << 1) + 1
#define root 1
using namespace std;

const int maxn = 100000 + 5, BIT = 20 + 5;
int N, Q, A[maxn], L, R, X, type;

struct Node {
  long long sum;
  int bit[BIT], tag;
} Seg[maxn << 2];

void build(int, int, int);
void pull(int);
long long query(int, int, int, int, int);
void push(int);
void modify(int, int, int, int, int, int);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> A[i];
  build(root, 0, N - 1);
  cin >> Q;
  while (Q--) {
    cin >> type;
    if (type == 1) {
      cin >> L >> R; L--; R--;
      cout << query(root, 0, N - 1, L, R) << '\n';
    }
    if (type == 2) {
      cin >> L >> R >> X; L--; R--;
      modify(root, 0, N - 1, L, R, X);
    }
  }
}

void build(int id, int L, int R) {
  if (L == R) {
    Seg[id].sum = A[L];
    memset(Seg[id].bit, -1, sizeof(Seg[id].bit));
    for (int i = 0, j = A[L]; j != 0; j >>= 1, ++i) Seg[id].bit[i] = (j & 1) ? 1 : -1;
    return;
  }
  int M = (L + R) >> 1;
  build(Lc(id), L, M);
  build(Rc(id), M + 1, R);
  pull(id);
}

void pull(int id) {
  Seg[id].sum = Seg[Lc(id)].sum + Seg[Rc(id)].sum;
  for (int i = 0; i < BIT; ++i) Seg[id].bit[i] = Seg[Lc(id)].bit[i] + Seg[Rc(id)].bit[i];
}

long long query(int id, int L, int R, int l, int r) {
  if (L > r || l > R) return 0;
  if (L >= l && R <= r) return Seg[id].sum;
  push(id);
  int M = (L + R) >> 1;
  return query(Lc(id), L, M, l, r) + query(Rc(id), M + 1, R, l, r);
}

void push(int id) {
  if (!Seg[id].tag) return;
  for (int i = 0, j = Seg[id].tag; j != 0; ++i, j >>= 1) {
    if (j & 1) {
      Seg[Lc(id)].bit[i] *= -1;
      Seg[Rc(id)].bit[i] *= -1;
      Seg[Lc(id)].sum += (1 << i) * Seg[Lc(id)].bit[i];
      Seg[Rc(id)].sum += (1 << i) * Seg[Rc(id)].bit[i];
    }
  }
  Seg[Lc(id)].tag ^= Seg[id].tag;
  Seg[Rc(id)].tag ^= Seg[id].tag;
  Seg[id].tag = 0;
}

void modify(int id, int L, int R, int l, int r, int x) {
  if (L > r || l > R) return;
  if (L >= l && R <= r) {
    for (int i = 0, j = x; j != 0; ++i, j >>= 1) {
      if (j & 1) Seg[id].bit[i] *= -1, Seg[id].sum += (1 << i) * Seg[id].bit[i];
    }
    Seg[id].tag ^= x;
    return;
  }
  push(id);
  int M = (L + R) >> 1;
  modify(Lc(id), L, M, l, r, x);
  modify(Rc(id), M + 1, R, l, r, x);
  pull(id);
}
