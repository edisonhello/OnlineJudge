#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> G[10];
int n, m, x, y, match[10], ans;
bool v[10];
bool DFS(int);

int main() {
  cin >> n >> m;
  while (m--) {
    cin >> x >> y;
    G[x].push_back(y);
  }
  memset(match, -1, sizeof(match));
  for (int i = 0; i < n; ++i) {
    memset(v, false, sizeof(v));
    if (DFS(i)) ans++;
  }
  cout << ans << endl;
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
