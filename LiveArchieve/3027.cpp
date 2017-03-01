#include <bits/stdc++.h>
using namespace std;

const int maxn = 20000 + 5;
int T, N;

struct Djs {
  int dsu[2][maxn];
  void init() {
    for (int i = 0; i < maxn; ++i) dsu[0][i] = i, dsu[1][i] = 0;
  }
  int F(int x) {
    if (dsu[0][x] == x) return x;
    dsu[1][x] += dsu[1][dsu[0][x]];
    return dsu[0][x] = F(dsu[0][x]);
  }
  void U(int x, int y) {
    dsu[0][x] = y;
    dsu[1][x] = abs(x - y) % 1000;
  }
  int query(int x) { return dsu[1][x]; }
} djs;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T; while (T--) {
    cin >> N;
    djs.init();
    char c;
    while (cin >> c, c != 'O') {
      if (c == 'E') {
        int I; cin >> I;
        djs.F(I);
        cout << djs.query(I) << '\n';
      }
      if (c == 'I') {
        int I, J; cin >> I >> J;
        djs.U(I, J);
      }
    }
  }
  return 0;
}
