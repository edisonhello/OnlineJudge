#include <cstdio>
#include <algorithm>
#define MAX (100000 + 5)
#define Lc(id) (id) * 2
#define Rc(id) (id) * 2 + 1
using namespace std;

int A[MAX], Seg[MAX << 2], N, Q;
char c1, c2, c3, c4, c5;
void build(int, int, int);
void pull(int);

int main() {
  scanf("%d %d", &N, &Q);
  for (int i = 1; i <= N; ++i) scanf("%d", A + i);
  build(1, 1, N);
  while (Q--) {
    
  }
}

void build(int id, int L, int R) {
  if (L == R) { Seg[id] = A[L]; return; }
  int M = (L + R) >> 1;
  build(Lc(id), L, M);
  build(Rc(id), M + 1, R);
  pull(id);
}

void pull(int id) {
  Seg[id] = min(Seg[Lc(id)], Seg[Rc(id)]);
}
