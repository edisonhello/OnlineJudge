#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> G[35];
bool v[35];
int m, ci, cj, n, t, cnt;
string s;
void DFS(int, int);

int main() {
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> s;
    for (int j = 1; j <= m; ++j) {
      if (s[j - 1] == '1') G[i].push_back(j);
    }
  }
  // for (int i = 1; i <= m; ++i) {
  //   cout << i << ": ";
  //   for (auto& j : G[i]) cout << j << " ";
  //   cout << endl;
  // }
  cin >> ci >> cj >> n;
  // ci--; cj--;
  // cout << ci << cj << n;
  // v[ci] = true;
  DFS(ci, 0);
  cout << cnt << endl;
  return 0;
}

void DFS(int x, int nw) {
  // cout << "x: " << x << " nw: " << nw << endl;
  if (nw > n) return;
  if (x == cj) { cnt += G[cj].size(); return; }
  for (auto i : G[x]) {
    // if (!v[i]) v[i] = true, DFS(i, nw + 1);
    DFS(i, nw + 1);
  }
}
