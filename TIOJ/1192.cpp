#include <bits/stdc++.h>
#define True(x) (x << 1)
#define False(x) (x << 1 | 1)
using namespace std;

const int maxl = 1000000 + 5, maxn = 1000 + 5;
vector<int> key[maxl];
vector<int> G[maxn << 1];
bool v[maxn << 1];
int T, n, L, S[maxn << 1], c;

void Init();
bool dfs(int);
bool TwoSat();

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T; while (T--) {
    Init();
    cin >> n >> L;
    for (int i = 1; i <= n; ++i) {
      int x;
      while (cin >> x, x) key[x].push_back(i);
      while (cin >> x, x) key[x].push_back(-i);
    }
    for (int i = 0; i < maxl; ++i) if (key[i].size()) {
      for (int j : key[i]) if (j > 0) {
        for (int k : key[i]) if (k < 0) {
          G[True(-k)].push_back(False(j));
          G[False(j)].push_back(True(-k));
          G[True(j)].push_back(False(-k));
          G[False(-k)].push_back(True(j));
        }
      }
    }
    for (int i = 0; i < maxl / 2; ++i) if (key[i].size() && key[L - i + 1].size()) {
      for (int j : key[i]) for (int k : key[L - i + 1]) {
        if (j > 0 && k < 0) {
          G[True(j)].push_back(True(-k));
          G[True(-k)].push_back(True(j));
          G[False(j)].push_back(False(-k));
          G[False(-k)].push_back(False(j));
        }
        if (j < 0 && k > 0) {
          G[True(k)].push_back(True(-j));
          G[True(-j)].push_back(True(k));
          G[False(k)].push_back(False(-j));
          G[False(-j)].push_back(False(k));
        }
      }
    }
    if (TwoSat()) cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}

void Init() {
  for (int i = 0; i < maxl; ++i) key[i].clear();
  for (int i = 0; i < maxn << 1; ++i) G[i].clear();
  memset(v, false, sizeof(v));
}

bool TwoSat() {
  for (int i = 0; i < maxn << 1; i += 2) {
    if (!v[i] && !v[i + 1]) {
      c = 0;
      if (!dfs(i)) {
        while (c) v[S[--c]] = false;
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
  for (int u : G[x]) if (!dfs(u)) return false;
  return true;
}
