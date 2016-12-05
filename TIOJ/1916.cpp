#include <iostream>
#include <cmath>
using namespace std;

int num[2005][2005], N, Q, r1, c1, r2, c2, target, tot;
bool ans;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  while (cin >> N, N) {
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) cin >> num[i][j];
    cin >> Q;
    while (Q--) {
      cin >> r1 >> r2 >> c1 >> c2;
      tot = 0; ans = false;
      for (int i = r1; i <= r2; ++i) for (int j = c1; j <= c2; ++j) tot += num[i][j];
      target = ceil(tot * 2 / (r2 - r1 + 1) * (c2 - c1 + 1));
      for (int i = r1; i <= r2; ++i) for (int j = c1; j <= c2; ++j) if (num[i][j] == target) ans = true;
      if (ans) cout << target << '\n';
      else cout << -1 << endl;
    }
  }
  return 0;
}
