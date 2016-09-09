#include <iostream>
#include <string>
#include <queue>
#include <utility>
#define pii pair<int, int>
#define MAXX 10
#define MAXY 17
#define X first
#define Y second
using namespace std;

string mp[10] = {
  "*****************",
  "*...*.......**..*",
  "**..*....*.*.*..*",
  "*......*.**.**.**",
  "*..**...**..**.**",
  "**.....**..*.*..*",
  "*....*..........*",
  "*.....****.*...**",
  "****.*.*........*",
  "*****************"
};

queue<pii> q;
int fx, fy, sx, sy, ex, ey;
//
// void BFS() {
//
// }

void fire(pii p, int t) {
  q.push(p);
  int ti = 0;
  while (ti < t * 4) {
    pii tmp = q.front();
    mp[tmp.X][tmp.Y] = '-';
    if (tmp.X + 1 < MAXX && tmp.Y < MAXY) if (mp[tmp.X + 1][tmp.Y] != '-') q.push(pii(tmp.X + 1, tmp.Y));
    if (tmp.X - 1 > -1 && tmp.Y < MAXY) if (mp[tmp.X - 1][tmp.Y] != '-') q.push(pii(tmp.X - 1, tmp.Y));
    if (tmp.Y - 1 > -1 && tmp.X < MAXX) if (mp[tmp.X][tmp.Y - 1] != '-') q.push(pii(tmp.X, tmp.Y - 1));
    if (tmp.Y + 1 < MAXY && tmp.X < MAXX) if (mp[tmp.X][tmp.Y + 1] != '-') q.push(pii(tmp.X, tmp.Y + 1));
    // if (ti == t * 4) BFS();
    q.pop();
  }
  // BFS();
}

int main() {
  int t;
  cin >> fx >> fy;
  cin >> t;
  cin >> sx >> sy >> ex >> ey;
  fire(pii(fx - 1, fy - 1), t);
  for (int i = 0; i < 10; ++i) {
    cout << mp[i] << endl;
  }
  return 0;
}
