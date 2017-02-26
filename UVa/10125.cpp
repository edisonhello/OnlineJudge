#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int s[maxn], n;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> n, n) {
    for (int i = 0; i < n; ++i) cin >> s[i];
    sort(s, s + n);
    bool ans = false;
    for (int d = n - 1; d >= 0 && !ans; --d) {
      for (int c = d - 1; c >= 0 && !ans; --c) {
        for (int b = c - 1; b >= 0 && !ans; --b) {
          for (int a = b - 1; a >= 0 && !ans; --a) {
            if (s[d] == s[a] + s[b] + s[c]) ans = true, cout << s[d] << '\n';
          }
        }
      }
    }
    if (!ans) cout << "no solution\n";
  }
  return 0;
}
