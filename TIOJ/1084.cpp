#include <iostream>
#include <set>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;

multiset<int> G[505];
int deg[505];
int M, __i, __j, start;
vector<pair<int, int>> edge;
void Euler(int);

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  while (cin >> M, M) {
    memset(deg, 0, sizeof(deg));
    for (int i = 0; i < 505; ++i) G[i].clear();
    edge.clear();
    for (int i = 0; i < M; ++i) {
      cin >> __i >> __j;
      G[__i].insert(__j), G[__j].insert(__i);
      deg[__i]++, deg[__j]++;
    }
    for (int i = 0; i < 10; ++i) {
      cout << i << ": ";
      for (auto& j : G[i]) cout << j << ' ';
      cout << endl;
    }
    for (int i = 0; i < 501; ++i) {
      if (deg[i] & 1) { start = i; break; }
    }
    cout << "start: " << start << endl;
    Euler(start);
    cout << edge[0].first << endl;
    for (int i = 0; i < edge.size(); ++i) cout << edge[i].second << endl;
  }
  return 0;
}

void Euler(int x) {
  if (edge.size() == M) return;
  for (auto i : G[x]) {
    edge.push_back({x, i});
    G[x].erase(i);
    G[i].erase(x);
    Euler(i);
    G[x].insert(i);
    G[i].insert(x);
    // break;
  }
}
