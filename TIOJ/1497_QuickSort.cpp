#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
string s;
int sa[maxn], r[2][maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  getline(cin, s);
  int n = (int)s.length();
  for (int i = 0; i < n; ++i) sa[i] = i;
  for (int i = 0; i < n; ++i) r[0][i] = s[i];
  int cur = 0;
  for (int m = 2; m <= n; m <<= 1) {
    auto cmp = [=](const int& i, const int& j) -> bool {
      if (r[cur][i] != r[cur][j]) return r[cur][i] < r[cur][j];
      int a = i + m / 2 < n ? r[cur][i + m / 2] : -1;
      int b = j + m / 2 < n ? r[cur][j + m / 2] : -1;
      return a < b;
    };
    sort(sa, sa + n, cmp);
    int rn = 0;
    r[cur ^ 1][sa[0]] = rn;
    for (int i = 1; i < n; ++i) {
      if (cmp(sa[i - 1], sa[i])) ++rn;
      r[cur ^ 1][sa[i]] = rn;
    }
    if (rn == n - 1) break;
    cur ^= 1;
  }
  for (int i = 0; i < n; ++i) cout << sa[i] << '\n';
  return 0;
}
