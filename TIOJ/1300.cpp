#include <bits/stdc++.h>
using namespace std;

struct S {
  int x, y, len;
};

const int dx[] = { -2, -2, 1, -1, 2, 2, 1, -1 }, dy[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
const int ddx[] = { -1, 0, 1, 0 }, ddy[] = { 0, 1, 0, -1 };
string mp[10];
int stx, sty, edx, edy;
bool v[10][10];
queue<S> q;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  while (cin >> mp[0]) {
    for (int i = 1; i < 10; ++i) cin >> mp[i];
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (mp[i][j] == 'P') stx = i, sty = j;
        if (mp[i][j] == 'E') edx = i, edy = j;
      }
    }
    memset(v, false, sizeof(v));
    while (q.size()) q.pop();
    q.push((S){ stx, sty, 0 });
    int ans = 0;
    while (q.size()) {
      S s = q.front(); q.pop();
      if (s.x == edx && s.y == edy) { ans = s.len; break; }
      v[s.x][s.y] = true;
      int x = s.x, y = s.y;
      for (int i = 0; i < 8; ++i) {
        if (x + dx[i] >= 0 && x + dx[i] < 10 && y + dy[i] >= 0 && y + dy[i] < 9) {
          if (!v[x + dx[i]][y + dy[i]] && mp[x + dx[i]][y + dy[i]] != 'S' && mp[x + ddx[i / 2]][y + ddy[i / 2]] != 'S') q.push((S){ x + dx[i], y + dy[i], s.len + 1 });
        }
      }
      for (int i = 0; i < 4; ++i) {
        if (x + ddx[i] >= 0 && x + ddx[i] < 10 && y + ddy[i] >= 0 && y + ddy[i] < 9) {
          if (!v[x + ddx[i]][y + ddy[i]] && mp[x + ddx[i]][y + ddy[i]] != 'S') q.push((S){ x + ddx[i], y + ddy[i], s.len + 1 });
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
