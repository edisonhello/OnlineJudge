#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5, maxm = 50 + 5;
int n, m, box[maxm], w[maxn], tot;

bool iddfs(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> m >> n;
  for (int i = 1; i <= m; ++i) cin >> box[i], tot += box[i];
  for (int i = 1; i <= n; ++i) cin >> w[i];
  sort(w + 1, w + n + 1);
  int dep, sum = 0;
  for (dep = 1; dep <= n; ++dep) {
    sum += w[dep];
    if (sum > tot) break;
    if (!iddfs(dep, -1)) break;
  }
  cout << dep - 1 << '\n';
}

bool iddfs(int b, int p) {
  if (b == 0) return true;
  int st = 1;
  if (p > 0 && w[b] == w[b + 1]) st = p;
  for (int i = st; i <= m; ++i) {
    if (w[b] > box[i]) continue;
    box[i] -= w[b];
    bool res = iddfs(b - 1, i);
    box[i] += w[b];
    if (res) return true;
  }
  return false;
}
