#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int n, A[30][30], dpa[1 << 10][1 << 10];
int dx[] = {1, 0, -1, 0, 0, 1, 1, -1, -1}, dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dp(int, int);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> A[i][j];
  cout << dp((1 << n) - 1, (1 << n) - 1) << endl;
}

int dp(int x, int y) {
  if (x == 0 || y == 0) return 0;
  if (dpa[x][y]) return dpa[x][y];
   // cout << "x: " << x << " y: " << y << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (x & (1 << i) && y & (1 << j)) {
        int xx = x, yy = y;
        xx ^= (1 << i); yy ^= (1 << j);
        for (int _ = 0; _ < 8; ++_) {
          if (i + dx[_] < n && i + dx[_] >= 0 && j + dy[_] < n && j + dy[_] >= 0) {
            xx ^= (1 << (i + dx[_])); yy ^= (1 << (j + dy[_]));
          }
        }
        dpa[x][y] = max(dpa[x][y], dp(xx, yy) + A[i][j]);
      }
    }
  }
  return dpa[x][y];
}
