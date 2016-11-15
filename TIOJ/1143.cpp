#include <iostream>
#include <queue>
using namespace std;

struct S {
  int x, y, len;
};

int mp[100][100], n, x, y, sx, sy, ex, ey;
short dx[] = {1, -1, -3, -3, -1, 1, 3, 3}, dy[] = {3, 3, 1, -1, -3, -3, -1, 1}, bx[] = {0, -1, 0, 1}, by[] = {1, 0, -1, 0};
S top;
bool v[100][100], p;
queue<S> q;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    mp[x][y] = 1;
  }
  cin >> sx >> sy >> ex >> ey;
  q.push((S){ sx, sy, 0 });
  while (!q.empty()) {
    top = q.front(), q.pop();
    if (top.x == ex && top.y == ey) { p = true; cout << top.len << endl; break; }
    for (int i = 0; i < 4; ++i) {
      if (top.x + bx[i] < 100 && top.x + bx[i] >= 0 && top.y + by[i] < 100 && top.y + by[i] >= 0 && !mp[top.x + bx[i]][top.y + by[i]]) {
        for (int _ = 0; _ < 2; ++_) {
          if (top.x + dx[i * 2 + _] < 100 && top.x + dx[i * 2 + _] >= 0 && top.y + dy[i * 2 + _] < 100 && top.y + dy[i * 2 + _] >= 0 && !v[top.x + dx[i * 2 + _]][top.y + dy[i * 2 + _]] && !mp[top.x + dx[i * 2 + _]][top.y + dy[i * 2 + _]]) {
            v[top.x + dx[i * 2 + _]][top.y + dy[i * 2 + _]] = true;
            q.push((S){ top.x + dx[i * 2 + _], top.y + dy[i * 2 + _], top.len + 1});
          }
        }
      }
    }
  }
  if (!p) cout << "impossible\n";
  return 0;
}
