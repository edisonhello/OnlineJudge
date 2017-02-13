#include <bits/stdc++.h>
#define Lc(id) (id << 1)
#define Rc(id) (id << 1 | 1)
#define lowbit(x) (x & -x)
using namespace std;

const int maxn = 200000 + 5;
vector<int> seg[maxn << 2];
int N, M, A[maxn], x, BIT[maxn], inv, pos[maxn];

int sum(int);
void add(int, int);
void build(int, int, int);
void pull(int);
int query1(int, int, int, int, int, int);
int query2(int, int, int, int, int, int);
void modify(int, int, int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  while (cin >> N >> M) {
    for (int i = 0; i < N; ++i) cin >> A[i], pos[A[i]] = i;
    inv = 0;
    for (int i = 0; i < N; ++i) {
      inv += i - sum(A[i]);
      add(A[i], 1);
    }
    memset(BIT, 0, sizeof(BIT));
    build(1, 0, N - 1);
    while (M--) {
      cin >> x;
      int a = 0, b = 0;
      if (pos[x]) a = query1(1, 0, N - 1, 0, pos[x] - 1, x);
      if (pos[x] != N - 1) b = query1(1, 0, N - 1, pos[x] + 1, N - 1, x);
      inv -= a + b;
      modify(1, 0, N - 1, pos[x]);
      cout << inv << '\n';
    }
  }
  return 0;
}

int sum(int x) {
  int ret = 0;
  while (x) ret += BIT[x], x -= lowbit(x);
  return ret;
}

void add(int x, int v) {
  while (x <= N) BIT[x] += v, x += lowbit(x);
}

void build(int id, int L, int R) {
  if (L == R) {
    seg[id].clear(); seg[id].push_back(A[L]);
    return;
  }
  int M = (L + R) >> 1;
  build(Lc(id), L, M);
  build(Rc(id), M + 1, R);
  pull(id);
}

void pull(int id) {
  seg[id].clear();
  int i = 0, j = 0;
  while (i < seg[Lc(id)].size() && j < seg[Rc(id)].size()) {
    if (seg[Lc(id)][i] < seg[Rc(id)][j]) seg[id].push_back(seg[Lc(id)][i++]);
    else seg[id].push_back(seg[Rc(id)][j++]);
  }
  while (i < seg[Lc(id)].size()) seg[id].push_back(seg[Lc(id)][i++]);
  while (j < seg[Rc(id)].size()) seg[id].push_back(seg[Rc(id)][j++]);
}

int query1(int id, int L, int R, int l, int r, int v) {
  if (L > r || l > R) return 0;
  if (L >= l && R <= r) {
    return seg[id].end() - upper_bound(seg[id].begin(), seg[id].end(), v);
  }
  int M = (L + R) >> 1;
  return query1(Lc(id), L, M, l, r, v) + query1(Rc(id), M + 1, R, l, r, v);
}

int query2(int id, int L, int R, int l, int r, int v) {
  if (L > r || l > R) return 0;
  if (L >= l && R <= r) {
    return lower_bound(seg[id].begin(), seg[id].end(), v) - seg[id].begin() - 1;
  }
  int M = (L + R) >> 1;
  return query2(Lc(id), L, M, l, r, v) + query2(Rc(id), M + 1, R, l, r, v);
}
void modify(int id, int L, int R, int x) {
  if (L == R) { seg[id].clear(); return; }
  int M = (L + R) >> 1;
  if (x <= M) modify(Lc(id), L, M, x);
  else modify(Rc(id), M + 1, R, x);
  pull(id);
}
