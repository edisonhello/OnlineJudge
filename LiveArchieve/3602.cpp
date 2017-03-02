#include <bits/stdc++.h>
using namespace std;

const int maxn = 50 + 5;
int T, n, m;
string s[maxn];

inline int hamming(const string&, const string&);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T; while (T--) {
    cin >> m >> n;
    for (int i = 0; i < m; ++i) cin >> s[i];
    string ans;
    int err = 0;
    for (int i = 0; i < n; ++i) {
      int cnt[26], Max = 0, ret = -1;
      memset(cnt, 0, sizeof(cnt));
      for (int j = 0; j < m; ++j) cnt[s[j][i] - 'A']++;
      for (int j = 0; j < 26; ++j) {
        if (cnt[j] > Max) Max = cnt[j], ret = j;
        else if (cnt[j] == Max) ret = min(ret, j);
      }
      ans += (char)(ret + 'A');
      err += (m - Max);
    }
    cout << ans << '\n' << err << '\n';
  }
  return 0;
}
