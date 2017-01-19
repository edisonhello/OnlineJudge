#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int maxw = 20 + 5;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
string mp[maxw];
int W, H, stx, sty, ans;
bool v[maxw][maxw];

void DFS(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> W >> H, (W || H)) {
    memset(v, false, sizeof(v));
    for (int i = 0; i < H; ++i) cin >> mp[i];
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) if (mp[i][j] == '@') stx = i, sty = j;
    ans = 0;
    DFS(stx, sty);
    cout << ans << '\n';
  }
  return 0;
}

void DFS(int x, int y) {
  v[x][y] = true;
  ans++;
  for (int i = 0; i < 4; ++i) if (x + dx[i] >= 0 && x + dx[i] < H && y + dy[i] >= 0 && y + dy[i] < W) {
    if (!v[x + dx[i]][y + dy[i]] && mp[x + dx[i]][y + dy[i]] == '.') DFS(x + dx[i], y + dy[i]);
  }
}
