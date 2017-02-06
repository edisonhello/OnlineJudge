#include <bits/stdc++.h>
#define Lc(id) id << 1
#define Rc(id) id << 1 | 1
using namespace std;

const int sigma = 26, maxn = 100000 + 5;

struct Seg {
  int cnt[sigma];
  int tag;
  Seg(): tag(-1) {}
} seg[maxn * 4];

int N, M, l, r, q[sigma], t;
string s;

void build(int, int, int);
void pull(int);
void query(int, int, int, int, int);
void ans(int, int, int);
void modify(int, int, int, int, int, int);
void push(int, int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N >> M;
  cin >> s;
  build(1, 0, N - 1);
  while (M--) {
    cin >> l >> r >> t; l--; r--;
    memset(q, 0, sizeof(q));
    query(1, 0, N - 1, l, r);
    if (t) {
      int it = l;
      for (int i = 0; i < sigma; ++i) {
        if (q[i]) modify(1, 0, N - 1, it, it + q[i] - 1, i);
        it += q[i];
      }
    } else {
      int it = l;
      for (int i = sigma - 1; i >= 0; --i) {
        if (q[i]) modify(1, 0, N - 1, it, it + q[i] - 1, i);
        it += q[i];
      }
    }
    // ans(1, 0, N - 1); cout << '\n';
  }
  ans(1, 0, N - 1); cout << '\n';
  return 0;
}

void build(int id, int L, int R) {
  if (L == R) {
    seg[id].cnt[s[L] - 'a'] = 1;
    return;
  }
  int M = (L + R) >> 1;
  build(Lc(id), L, M);
  build(Rc(id), M + 1, R);
  pull(id);
}

void pull(int id) {
  for (int i = 0; i < sigma; ++i) seg[id].cnt[i] = seg[Lc(id)].cnt[i] + seg[Rc(id)].cnt[i];
}

void query(int id, int L, int R, int l, int r) {
  push(id, L, R);
  if (L > r || l > R) return;
  if (L >= l && R <= r) {
    for (int i = 0; i < sigma; ++i) q[i] += seg[id].cnt[i];
    return;
  }
  int M = (L + R) >> 1;
  query(Lc(id), L, M, l, r);
  query(Rc(id), M + 1, R, l, r);
}

void ans(int id, int L, int R) {
  push(id, L, R);
  if (L == R) {
    for (int i = 0; i < sigma; ++i) if (seg[id].cnt[i]) cout << (char)(i + 'a');
    return;
  }
  int M = (L + R) >> 1;
  ans(Lc(id), L, M);
  ans(Rc(id), M + 1, R);
}

void modify(int id, int L, int R, int l, int r, int v) {
  push(id, L, R);
  if (L > r || l > R) return;
  if (L >= l && R <= r) {
    for (int i = 0; i < sigma; ++i) seg[id].cnt[i] = 0;
    seg[id].cnt[v] = R - L + 1;
    if (L == R) return;
    seg[Lc(id)].tag = v;
    seg[Rc(id)].tag = v;
    return;
  }
  int M = (L + R) >> 1;
  modify(Lc(id), L, M, l, r, v);
  modify(Rc(id), M + 1, R, l, r, v);
  pull(id);
}

void push(int id, int L, int R) {
  if (seg[id].tag == -1) return;
  for (int i = 0; i < sigma; ++i) seg[id].cnt[i] = 0;
  seg[id].cnt[seg[id].tag] = R - L + 1;
  if (L == R) { seg[id].tag = -1; return; }
  seg[Lc(id)].tag = seg[id].tag;
  seg[Rc(id)].tag = seg[id].tag;
  seg[id].tag = -1;
}
