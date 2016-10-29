#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int n, x, y;
bitset<105> v, vv;
vector<int> G[105], T[105];
bool p;
bool DFS(int, int);

int main() {
  while (cin >> n, n) {
    for (int i = 0; i < n - 1; ++i) {
      cin >> x >> y;
      G[x].push_back(y); G[y].push_back(x);
    }
    for (int i = 0; i < n - 1; ++i) {
      cin >> x >> y;
      T[x].push_back(y);
      T[y].push_back(x);
    }
    // v[1] = true; vv[1] = true;
    p = false;
    for (int i = 1; i <= n; ++i) {
      v.reset(); vv.reset();
      v[1] = true; vv[i] = true;
      if (DFS(1, i)) { p = true; break; }
    }
    if (p) cout << "Same\n";
    else cout << "Different\n";
  }
  return 0;
}

bool DFS(int g, int t) {
  if (G[g].size() != T[t].size()) return false;
  for (int i = 0; i < G[g].size(); ++i) {
    if (!v[G[g][i]] && !vv[T[t][i]]) {
      v[G[g][i]] = true; vv[T[t][i]] = true;
      return DFS(G[g][i], T[t][i]);
    }
  }
  return true;
}
