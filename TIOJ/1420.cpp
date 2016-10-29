#include <iostream>
#include <vector>
#include <set>
using namespace std;

int a, b, c, x, y, v[10005][10005], cnt;
set<int> G[50005];
bool vv[50005];
int d[] = {1, 0, 0, 1, -1, 0, 0, -1, 1, 1, -1, -1, 1, -1, -1, 1};
void DFS(int);

int main() {
  cin >> a >> b >> c;
  for (int i = 1; i <= c; ++i) {
    cin >> y >> x;
    if (v[x][y] != i && v[x][y] > 0) G[i].insert(v[x][y]), G[v[x][y]].insert(i);
    v[x][y] = i;
    for (int j = 0; j < 8; ++j) {
      if (x + d[j * 2] >= 1 && x + d[j * 2] <= b && y + d[j * 2 + 1] >= 1 && y + d[j * 2 + 1] <= a) {
        if (v[x + d[j * 2]][y + d[j * 2 + 1]] != i && v[x + d[j * 2]][y + d[j * 2 + 1]] > 0) {
          G[i].insert(v[x + d[j * 2]][y + d[j * 2 + 1]]);
          G[v[x + d[j * 2]][y + d[j * 2 + 1]]].insert(i);
        }
        v[x + d[j * 2]][y + d[j * 2 + 1]] = i;
      }
    }
  }
  cnt = 0;
  for (int i = 1; i <= c; ++i) {
    if (!vv[i]) {
      vv[i] = true;
      DFS(i);
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}

void DFS(int x) {
  for (auto i : G[x]) {
    if (!vv[i]) {
      vv[i] = true;
      DFS(i);
    }
  }
}
