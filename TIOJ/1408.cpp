#include <iostream>
#define Lc(x) x*2
#define Rc(x) x*2+1
#define M (L+R)>>1
using namespace std;

int seg[400005];
int n;
void build(int, int, int);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  while (cin >> n) {
    build(1, n, 1);
    for (int i = 0; i < n; ++i) {
      cin >> a >> b >> c;
      modify()
    }
  }
}

void build(int L, int R, int id) {
  if (L == R) seg[id] = 0;
  build(L, M, Lc(id)); build(M + 1, R, Rc(id));
}
