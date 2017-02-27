#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int T, S, A, m, s[maxn], c;
vector<int> G[maxn];
bool v[maxn];

bool TwoSat();
bool dfs(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T; while (T--) {
    cin >> S >> A >> m;
    for (int i = 0; i < maxn; ++i) G[i].clear();
    memset(v, false, sizeof(v));
    memset(s, 0, sizeof(s));
    while (m--) {
      int s1, a1, s2, a2; cin >> s1 >> a1 >> s2 >> a2;
      if (s1 > s2 && a1 > a2) {
        G[a1 << 1 | 1].push_back((s2 + 30) << 1 | 1), G[(s2 + 30) << 1 | 1].push_back(a1 << 1 | 1);
        G[a2 << 1 | 1].push_back((s1 + 30) << 1 | 1), G[(s1 + 30) << 1 | 1].push_back(a2 << 1 | 1);
      }
      if (s1 > s2 && a1 < a2) {
        G[a1 << 1 | 1].push_back((s2 + 30) << 1), G[(s2 + 30) << 1].push_back(a1 << 1 | 1);
        G[a2 << 1 | 1].push_back((s1 + 30) << 1), G[(s1 + 30) << 1].push_back(a2 << 1 | 1);
      }
      if (s1 < s2 && a1 > a2) {
        G[a1 << 1].push_back((s2 + 30) << 1), G[(s2 + 30) << 1].push_back(a1 << 1);
        G[a2 << 1].push_back((s1 + 30) << 1), G[(s1 + 30) << 1].push_back(a2 << 1);
      }
      if (s1 < s2 && a1 < a2) {
        G[a1 << 1].push_back((s2 + 30) << 1 | 1), G[(s2 + 30) << 1 | 1].push_back(a1 << 1);
        G[a2 << 1].push_back((s1 + 30) << 1 | 1), G[(s1 + 30) << 1 | 1].push_back(a2 << 1);
      }
    }
    if (TwoSat()) cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}

bool TwoSat() {
  for (int i = 0; i <= 120; i += 2) {
    if (!v[i] && !v[i + 1]) {
      c = 0;
      if (!dfs(i)) {
        while (c) v[s[--c]] = false;
        if (!dfs(i + 1)) return false;
      }
    }
  }
  return true;
}

bool dfs(int x) {
  if (v[x ^ 1]) return false;
  if (v[x]) return true;
  v[x] = true;
  s[c++] = x;
  for (int u : G[x]) if (!dfs(u)) return false;
  return true;
}
