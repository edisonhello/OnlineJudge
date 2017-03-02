#include <bits/stdc++.h>
using namespace std;

int T, n, kase;
string s[15];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T; while (T--) {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (s[i][j] != '.') continue;
        bool ban[26];
        memset(ban, false, sizeof(ban));
        if (i) if (s[i - 1][j] != '.') ban[s[i - 1][j] - 'A'] = true;
        if (i < n - 1) if (s[i + 1][j] != '.') ban[s[i + 1][j] - 'A'] = true;
        if (j) if (s[i][j - 1] != '.') ban[s[i][j - 1] - 'A'] = true;
        if (j < n - 1) if (s[i][j + 1] != '.') ban[s[i][j + 1] - 'A'] = true;
        int k = 0; while (ban[k]) ++k;
        s[i][j] = (char)('A' + k);
      }
    }
    cout << "Case " << ++kase << ":\n";
    for (int i = 0; i < n; ++i) cout << s[i] << '\n';
  }
  return 0;
}
