#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string mp[1000];
bool v[1000][1000];
int m, n, cnt;

void DFS(int, int);

int main() {
  while (cin >> m >> n) {
    if (m == 0 && n == 0) break;
    for (int i = 0; i < m; ++i) cin >> mp[i];
    memset(v, false, sizeof(v));
    cnt = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!v[i][j] && mp[i][j] == '1') {v[i][j] = true; cnt++; DFS(i, j);}
      }
    }
    cout << cnt << endl;
  }
  return 0;
}

void DFS(int y, int x) {
  if ( y + 1 < m && !v[y + 1][x] && mp[y + 1][x] == mp[y][x]) {v[y + 1][x] = true; DFS(y + 1, x);}
  if (y - 1 >= 0 && !v[y - 1][x] && mp[y - 1][x] == mp[y][x]) {v[y - 1][x] = true; DFS(y - 1, x);}
  if ( x + 1 < n && !v[y][x + 1] && mp[y][x + 1] == mp[y][x]) {v[y][x + 1] = true; DFS(y, x + 1);}
  if (x - 1 >= 0 && !v[y][x - 1] && mp[y][x - 1] == mp[y][x]) {v[y][x - 1] = true; DFS(y, x - 1);}
  if ( y + 1 < m && x + 1 < n && !v[y + 1][x + 1] && mp[y + 1][x + 1] == mp[y][x]) {v[y + 1][x + 1] = true; DFS(y + 1, x + 1);}
  if (y + 1 < m && x - 1 >= 0 && !v[y + 1][x - 1] && mp[y + 1][x - 1] == mp[y][x]) {v[y + 1][x - 1] = true; DFS(y + 1, x - 1);}
  if ( x + 1 < n && y - 1 >= 0 && !v[y - 1][x + 1] && mp[y - 1][x + 1] == mp[y][x]) {v[y - 1][x + 1] = true; DFS(y - 1, x + 1);}
  if (x - 1 >= 0 && y - 1 >= 0 && !v[y - 1][x - 1] && mp[y - 1][x - 1] == mp[y][x]) {v[y - 1][x - 1] = true; DFS(y - 1, x - 1);}
}
