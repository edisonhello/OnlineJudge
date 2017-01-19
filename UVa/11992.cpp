#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <tuple>
#define Lc(id) (id) << 1
#define Rc(id) (id) << 1 | 1
#define root 1
using namespace std;

const int maxn = 1000000 + 5;

struct Seg {
  int Sum, Min, Max;
  int tag, seg;
} seg[25][maxn << 2];

int R, C, M, t, x1, y1, x2, y2;

void add(int, int, int, int, int, int, int);
void set(int, int, int, int, int, int, int);
tuple<int, int, int> query(int, int, int, int, int);
void push(int, int);
void pull(int, int);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  while (cin >> R >> C >> M) {
    memset(seg, 0, sizeof(seg));
    while (M--) {
      cin >> t;
      if (t == 1) {
        cin >> x1 >> y1 >> x2 >> y2 >> v;
        for (int i = x1; i <= x2; ++i) add(root, i, 1, C, y1, y2, v);
      }
      if (t == 2) {
        cin >> x1 >> y1 >> x2 >> y2 >> v;
        for (int i = x1; i <= x2; ++i) set(root, i, 1, C, y1, y2, v);
      }
      if (t == 3) {
        cin >> x1 >> y1 >> x2 >> y2;
        tuple<int, int, int> ret = { 0, INT_MAX, 0 };
        for (int i = x1; i <= x2; ++i) {
          tuple<int, int, int> res = query(root, 1, C, y1, y2);
          get<0>(ret) += get<0>(res);
          get<1>(ret) = min(get<1>(ret), get<1>(res));
          get<2>(ret) = max(get<2>(ret), get<2>(res));
        }
        cout << get<0>(ret) << ' ' << get<1>(ret) << ' ' << get<2>(ret) << '\n';
      }
    }
  }
  return 0;
}

void add(int id, int i, int L, int R, int l, int r, int v) {
  if (L > r || l > R) return;
  if (L >= l && R <= R) { seg[i][id].add += v; return; }
  push(id, i);
  int M = (L + R) >> 1;
  add(Lc(id), i, L, M, l, r, v);
  add(Rc(id), i, M + 1, R, l, r, v);
  pull(id, i);
}

void set(int id, int i, int L, int R, int l, int r, int v) {
  if (L > r || l > R) return;
  if (L >= l && R <= r) { seg[i][id].set = v; return; }
  push(id, i);
  int M = (L + R) >> 1;
  add(Lc(id), i, L, M, l, r, v);
  add(Rc(id), i, M + 1, R, l, r, v);
  pull(id, i);
}

void push(int id, int i) {

}
