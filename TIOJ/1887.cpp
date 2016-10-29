#include <cstdio>
#include <algorithm>
#define MOD (int)(1e9 + 7)
using namespace std;

struct Node {
  int X, Y;
};

Node seg[2000010];
char __c;
int T;
bool flag;
int X[500010], Y[500010], N, M, K, P, V;
void build(int, int, int);
void modify_X(int, int, int, int, int);
void modify_Y(int, int, int, int, int);
int query(int, int, int);

template <typename T>
inline bool rit(T& x) {
  __c = 0; flag = false;
  while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
  __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
  while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
  if (flag) x = -x;
  return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) {return rit(x) && rit(args...);}

inline int Lc(int id) {return id * 2;}
inline int Rc(int id) {return id * 2 + 1;}

int main() {
  rit(T);
  while (T--) {
    rit(N);
    for (int i = 0; i < N; ++i) rit(X[i]);
    for (int i = 0; i < N; ++i) rit(Y[i]);
    build(0, N - 1, 1);
    printf("%d\n", (seg[1].X * seg[1].Y) % MOD);
    rit(M);
    while (M--) {
      rit(K, P, V);
      if (K == 1) modify_X(0, N - 1, P, V, 1), printf("%d\n", (seg[1].X * seg[1].Y) % MOD);
      if (K == 2) modify_Y(0, N - 1, P, V, 1), printf("%d\n", (seg[1].X * seg[1].Y) % MOD);
    }
  }
  return 0;
}

void build(int L, int R, int id) {
  if (L == R) { seg[id].X = X[L]; seg[id].Y = Y[L]; return; }
  int m = (L + R) / 2;
  build(L, m, Lc(id)), build(m + 1, R, Rc(id));
  seg[id].X = seg[Lc(id)].X * seg[Rc(id)].X;
  seg[id].Y = max(seg[Lc(id)].Y, seg[Rc(id)].Y);
}

void modify_X(int L, int R, int P, int V, int id) {
  if (L > P || R < P) return;
  if (L == P && R == P) { seg[id].X = V; return; }
  int m = (L + R) / 2;
  modify_X(L, m, P, V, Lc(id)), modify_X(m + 1, R, P, V, Rc(id));
  seg[id].X = seg[Lc(id)].X * seg[Rc(id)].X;
  seg[id].Y = max(seg[Lc(id)].Y, seg[Rc(id)].Y);
}

void modify_Y(int L, int R, int P, int V, int id) {
  if (L > P || R < P) return;
  if (L == P && R == P) { seg[id].Y = V; return; }
  int m = (L + R) / 2;
  modify_Y(L, m, P, V, Lc(id)), modify_Y(m + 1, R, P, V, Rc(id));
  seg[id].X = seg[Lc(id)].X * seg[Rc(id)].X;
  seg[id].Y = max(seg[Lc(id)].Y, seg[Rc(id)].Y);
}
