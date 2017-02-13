#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 50000 + 5, lg = 16;
struct St { int Max, Min; } st[lg][maxn];
int N, Q, h[maxn], a, b;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> N >> Q;
  for (int i = 0; i < N; ++i) cin >> h[i];
  for (int i = 0; i < N; ++i) st[0][i].Max = st[0][i].Min = h[i];
  for (int i = 1; (1 << i) <= N; ++i) {
    for (int j = 0; j + (1 << i) <= N; ++j) {
      st[i][j].Max = max(st[i - 1][j].Max, st[i - 1][j + (1 << (i - 1))].Max);
      st[i][j].Min = min(st[i - 1][j].Min, st[i - 1][j + (1 << (i - 1))].Min);
    }
  }
  while (Q--) {
    cin >> a >> b; --a, --b;
    int p = 31 - __builtin_clz(abs(b - a) + 1);
    cout << max(st[p][a].Max, st[p][b - (1 << p) + 1].Max) - min(st[p][a].Min, st[p][b - (1 << p) + 1].Min) << '\n';
  }
  return 0;
}
