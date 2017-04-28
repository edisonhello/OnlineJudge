#include <bits/stdc++.h>
using namespace std;

// vector<int> v;
int osas[15] = { 13,8,12,9,6,4,3,7,11,10,15,1,5,2,14 };
vector<int> G[20];
bool v[20];

void dfs(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  // for (int i = 1; i <= 15; ++i) v.push_back(i);
  // random_shuffle(v.begin(), v.end());
  // for (int i : v) cout << i << ",";
  for (int i = 0; i < 15; ++i) {
    G[i + 1].push_back(osas[i]);
  }
  int cycle = 0;
  for (int i = 1; i <= 15; ++i) if (!v[i]) ++cycle, dfs(i, i);
  cout << 15 - cycle << '\n';
  return 0;
}

void dfs(int x, int st) {
  v[x] = true;
  for (int i : G[x]) {
    if (i == st) return;
    if (!v[i]) dfs(i, st);
  }
}
