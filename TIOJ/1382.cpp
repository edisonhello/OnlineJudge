#include <cstdio>
#include <cstring>
#define Lc(id) (id) << 1
#define Rc(id) (id) << 1 | 1
#define root 1
#define getchar gtx
using namespace std;

char __c;
bool flag;

inline int gtx() {
  const int N = 1048576;
  static char buffer[N];
  static char *p = buffer, *end = buffer;
  if (p == end) {
    if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
    p = buffer;
  }
  return *p++;
}

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

const int maxn = 100000 + 5;
int seg[maxn << 2], A, N, jizz;

void build(int, int, int);
void pull(int);
int modify(int, int, int, int);

int main() {
  while (rit(N)) {
    build(root, 1, N);
    jizz = 1;
    while (seg[root]) {
      rit(A);
      jizz = (jizz + A - 1) % seg[root];
      if (!jizz) jizz = seg[root];
      printf("%d ", modify(root, 1, N, jizz));
    }
    puts("");
  }
  return 0;
}

void build(int id, int L, int R) {
  if (L == R) { seg[id] = 1; return; }
  int M = (L + R) >> 1;
  build(Lc(id), L, M);
  build(Rc(id), M + 1, R);
  pull(id);
}

void pull(int id) {
  seg[id] = seg[Lc(id)] + seg[Rc(id)];
}

int modify(int id, int L, int R, int x) {
  seg[id]--;
  if (L == R) { seg[id] = 0; return L; }
  int M = (L + R) >> 1;
  if (x <= seg[Lc(id)]) return modify(Lc(id), L, M, x);
  else return modify(Rc(id), M + 1, R, x - seg[Lc(id)]);
}
