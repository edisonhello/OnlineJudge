#include <bits/stdc++.h>
using namespace std;

const int maxn = 50000 + 5, lg = 16;
int T, g, kase, sa[maxn], r[2][maxn], N, rn[maxn], h[maxn], st[lg][maxn];
string s;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T;
  while (T--) {
    cin >> g >> s;
    N = (int)s.length();
    for (int i = 0; i < N; ++i) sa[i] = i;
    for (int i = 0; i < N; ++i) r[0][i] = s[i];
    for (int m = 2; m <= N; m <<= 1) {
      auto cmp = [m](int i, int j) -> bool {
        if (r[0][i] != r[0][j]) return r[0][i] < r[0][j];
        int a = i + m / 2 < N ? r[0][i + m / 2] : -1;
        int b = j + m / 2 < N ? r[0][j + m / 2] : -1;
        return a < b;
      };
      sort(sa, sa + N, cmp);
      int R = 0;
      r[1][sa[0]] = R;
      for (int i = 1; i < N; ++i) {
        if (cmp(sa[i - 1], sa[i])) ++R;
        r[1][sa[i]] = R;
      }
      swap(r[0], r[1]);
      if (R == N - 1) break;
    }
    for (int i = 0; i < N; ++i) rn[sa[i]] = i;
    int k = 0;
    for (int i = 0; i < N; ++i) {
      if (k) --k;
      int j = sa[rn[i] - 1];
      while (s[i + k] == s[j + k]) ++k;
      h[rn[i]] = k;
    }
    for (int i = 0; i < N; ++i) st[0][i] = h[i];
    for (int i = 1; (1 << i) <= N; ++i) {
      for (int j = 0; j + (1 << i) <= N; ++j) {
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
    
  }
  return 0;
}
