#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int N, tin[maxn], stamp, low[maxn], ans, a, b;
vector<int> G[maxn];
bool cut[maxn];
string s;

void Init();
int DFS(int, int);

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(nullptr);
  while (scanf("%d ", &N), N) {
    Init();
    while (getline(cin, s), s[0] != '0') {
      stringstream ss(s); ss >> a;
      while (ss >> b) G[a].push_back(b), G[b].push_back(a);
    }
    DFS(1, 0);
    for (int i = 1; i <= N; ++i) if (cut[i]) ++ans;
    cout << ans << '\n';
  }
  return 0;
}

void Init() {
  for (int i = 0; i < maxn; ++i) G[i].clear();
  memset(tin, 0, sizeof(tin));
  memset(low, 0, sizeof(low));
  memset(cut, false, sizeof(cut));
  stamp = 0; ans = 0;
}

int DFS(int x, int fa) {
  tin[x] = ++stamp;
  low[x] = tin[x];
  int ch = 0;
  for (int u : G[x]) {
    if (!tin[u]) {
      ++ch;
      int lowu = DFS(u, x);
      low[x] = min(low[x], lowu);
      if (lowu >= tin[x]) cut[x] = true;
    } else if (tin[u] < tin[x] && u != fa) low[x] = min(low[x], tin[u]);
  }
  if (!fa && ch == 1) cut[x] = false;
  return low[x];
}
