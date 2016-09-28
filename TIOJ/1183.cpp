#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

string mp[20], sol;
int t, n, m, sx, sy, tx, ty;

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      cin >> mp[i];
      for (int j = 0; j < m; ++j) {
        if (mp[i][j] == 'S') {sx = j; sy = i;}
        if (mp[i][j] == 'T') {tx = j; ty = i;}
      }
    }
    sol = "";
    while (sx != tx || sy != ty) {
      if (sy + 1 < n && (mp[sy + 1][sx] == '.' || mp[sy + 1][sx] == 'T')) {mp[sy][sx] = 'J'; sy++; sol += 'D';}
      else if (sy - 1 >= 0 && (mp[sy - 1][sx] == '.' || mp[sy - 1][sx] == 'T')) {mp[sy][sx] = 'J'; sy--; sol += 'U';}
      else if (sx + 1 < m && (mp[sy][sx + 1] == '.' || mp[sy][sx + 1] == 'T')) {mp[sy][sx] = 'J'; sx++; sol += 'R';}
      else if (sx - 1 >= 0 && (mp[sy][sx - 1] == '.' || mp[sy][sx - 1] == 'T')) {mp[sy][sx] = 'J'; sx--; sol += 'L';}
    }
    cout << sol << endl;
  }
  return 0;
}
