#include <bits/stdc++.h>
using namespace std;

stringstream ss;
string s;
int T, t[26], _dp[26], in[26], st, ans, start;
vector<int> G[26];

void Init();
void dp(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  getline(cin, s); ss << s; ss >> T; getline(cin, s);
  while (T--) {
    Init();
    while (getline(cin, s), s != "") {
      ss.clear(); ss << s;
      char b, c; ss >> c; ss >> t[c - 'A'];
      bool flag = true;
      while (ss >> b) {
        G[b - 'A'].push_back(c - 'A');
        flag = false;
      }
      if (flag) start = c - 'A';
    }
    ans = 0;
    dp(start, 0);
    cout << ans << "\n\n";
  }
  return 0;
}

void Init() {
  memset(in, 0, sizeof(in));
  memset(_dp, 0, sizeof(_dp));
  for (int i = 0; i < 26; ++i) G[i].clear();
}

void dp(int x, int sum) {
  ans = max(ans, sum + t[x]);
  for (int u : G[x]) dp(u, sum + t[x]);
}
