#include <cstdio>
#include <fstream>
#define getchar getchar_unlocked
#define MAX 500000
using namespace std;

char __c;
bool flag;

template <typename T>
inline bool rit(T& x) {
  __c = 0, flag = false;
  while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
  __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
  while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
  if (flag) x = -x;
  return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

int djs[MAX * 3 + 5];
int N, K, D, X, Y, cnt;

int F(int x) { return djs[x] == x ? x : djs[x] = F(djs[x]); }

void U(int x, int y) {
  x = F(x); y = F(y);
  djs[x] = y;
}

int main() {
  // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
  for (int i = 0; i < 3 * MAX + 5; ++i) djs[i] = i;
  rit(N, K);
  while (K--) {
    rit(D, X, Y);
    if (X > N || X < 1 || Y > N || Y < 1) { cnt++; continue; }
    if (D == 1) {
      if (F(X) == F(Y + MAX) || F(Y) == F(X + MAX)) { cnt++; continue; }
      U(X, Y); U(X + MAX, Y + MAX); U(X + MAX * 2, Y + MAX * 2);
    } else {
      if (F(X) == F(Y) || F(X + MAX) == F(Y)) { cnt++; continue; }
      U(X, Y + MAX); U(X + MAX, Y + MAX * 2); U(X + MAX * 2, Y);
    }
  }
  printf("%d\n", cnt);
  return 0;
}
