#include <bits/stdc++.h>
#define Lc(id) (id << 1)
#define Rc(id) (id << 1 | 1)
using namespace std;

const int maxn = 50000 + 5;
map<int, int> seg[maxn << 2];
int N, M, A[maxn];
char tp;

void build(int, int, int);
void pull(int);
void modify(int, int, int, int, int);
map<int, int> query(int, int, int, int, int);
map<int, int> merge(const map<int, int>&, const map<int, int>&);

int main() {
  freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  while (cin >> N >> M) {
    for (int i = 0; i < N; ++i) cin >> A[i];
    build(1, 0, N - 1);
    while (M--) {
      cin >> tp;
      if (tp == 'M') {
        int x, y; cin >> x >> y;
        modify(1, 0, N - 1, x, y);
      }
      if (tp == 'Q') {
        int x, y; cin >> x >> y; --y;
        cout << query(1, 0, N - 1, x, y).size() << '\n';
      }
    }
  }
  return 0;
}

void build(int id, int L, int R) {
  if (L == R) {
    seg[id].clear();
    seg[id][A[L]] = 1;
    return;
  }
  int M = (L + R) >> 1;
  build(Lc(id), L, M); build(Rc(id), M + 1, R);
  pull(id);
}

void pull(int id) {
  seg[id].clear();
  for (auto i : seg[Lc(id)]) seg[id][i.first] += i.second;
  for (auto i : seg[Rc(id)]) seg[id][i.first] += i.second;
}

void modify(int id, int L, int R, int x, int y) {
  if (L == R) {
    seg[id].clear();
    seg[id][y] = 1;
    return;
  }
  int M = (L + R) >> 1;
  if (x <= M) modify(Lc(id), L, M, x, y);
  else modify(Rc(id), M + 1, R, x, y);
  pull(id);
}

map<int, int> query(int id, int L, int R, int l, int r) {
  if (L > r || l > R) return map<int, int>();
  if (L >= l && R <= r) return seg[id];
  int M = (L + R) >> 1;
  return merge(query(Lc(id), L, M, l, r), query(Rc(id), M + 1, R, l, r));
}

map<int, int> merge(const map<int, int>& a, const map<int, int>& b) {
  map<int, int> ret;
  for (auto i : a) ret[i.first] += i.second;
  for (auto i : b) ret[i.first] += i.second;
  return ret;
}
