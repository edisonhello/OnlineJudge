#include <bits/stdc++.h>
using namespace std;

const int maxn = 26;
int N, M;
vector<int> G[maxn];
bool w[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> N >> M) {
    for (int i = 0; i < 26; ++i) G[i].clear();
    memset(w, false, sizeof(w));
    string s; cin >> s;
    for (int i = 0; i < s.length(); ++i) w[s[i] - 'A'] = true;
    while (M--) {
      char a, b; cin >> a >> b;
      G[a - 'A'].push_back(b - 'A');
      G[b - 'A'].push_back(a - 'A');
    }
    int wake = (int)s.length(), y = 0;
    while (true) {
      if (wake == N) break;
      bool mod = false;
      vector<int> chg;
      for (int i = 0; i < 26; ++i) {
        if (w[i]) continue;
        int cnt = 0;
        for (int u : G[i]) if (w[u]) ++cnt;
        if (cnt >= 3) chg.push_back(i), mod = true, ++wake;
      }
      ++y;
      if (!mod) break;
      for (int i : chg) w[i] = true;
    }
    if (wake == N) cout << "WAKE UP IN, " << y << ", YEARS\n";
    else cout << "THIS BRAIN NEVER WAKES UP\n";
  }
  return 0;
}
