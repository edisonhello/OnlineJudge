#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int T, N, M, x, y, match[505], ans;
bool v[505];
vector<int> G[505];
bool DFS(int);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    for (int i = 0; i < 505; ++i) G[i].clear();
    cin >> N >> M; ans = 0;
    while (M--) {
      cin >> x >> y;
      G[x].push_back(y);
    }
    memset(match, -1, sizeof(match));
    for (int i = 0; i < N; ++i) {
      memset(v, false, sizeof(v));
      if (DFS(i)) ans++;
    }
    cout << ans << '\n';
  }
  return 0;
}

bool DFS(int x) {
  v[x] = true;
  for (int i : G[x]) {
    if (match[i] == -1 || !v[match[i]] && DFS(match[i])) {
      match[i] = x;
      return true;
    }
  }
  return false;
}
