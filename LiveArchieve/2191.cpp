#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#define Lc(id) (id) << 1
#define Rc(id) (id) << 1 | 1
#define root 1
using namespace std;

const int maxn = 200000 + 5;

int Seg[maxn << 2], N, A[maxn], x, r, y, kase;
string s;

void build(int, int, int);
void pull(int);
void modify(int, int, int, int, int);
long long query(int, int, int, int, int);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  while (cin >> N, N) {
    memset(Seg, 0, sizeof(Seg));
    for (int i = 1; i <= N; ++i) cin >> A[i];
    build(root, 1, N);
    cout << "Case " << ++kase << ":\n";
    while (cin >> s, s != "END") {
      if (s == "S") cin >> x >> r, modify(root, 1, N, x, r);
      if (s == "M") {
        cin >> x >> y;
        if (x > y) assert(1 == 0);
        cout << query(root, 1, N, x, y) << '\n';
      }
    }
    cout << '\n';
  }
  return 0;
}

void build(int id, int L, int R) {
  if (L == R) { Seg[id] = A[L]; return; }
  int M = (L + R) >> 1;
  build(Lc(id), L, M);
  build(Rc(id), M + 1, R);
  pull(id);
}

void pull(int id) {
  Seg[id] = Seg[Lc(id)] + Seg[Rc(id)];
}

void modify(int id, int L, int R, int x, int r) {
  if (L == R) { Seg[id] = r; return; }
  int M = (L + R) >> 1;
  if (x <= M) modify(Lc(id), L, M, x, r);
  else modify(Rc(id), M + 1, R, x, r);
  pull(id);
}

long long query(int id, int L, int R, int x, int y) {
  if (L > y || x > R) return 0;
  if (L >= x && R <= y) return Seg[id];
  int M = (L + R) >> 1;
  return query(Lc(id), L, M, x, y) + query(Rc(id), M + 1, R, x, y);
}
