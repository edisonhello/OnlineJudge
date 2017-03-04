#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000 + 5;
int n;
struct Osas { int len, R; } p[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> p[i].R >> p[i].len;
  sort(p, p + n, [](const Osas& a, const Osas& b) {
    return a.R == b.R ? a.len < b.len : a.R < b.R;
  });
  int ind = 0, ans = 0;
  for (int i = 0; i < n; ++i) {
    if (ind + p[i].len > p[i].R) continue;
    ++ans;
    ind += p[i].len;
  }
  cout << ans << '\n';
  return 0;
}
