#include <iostream>
#include <string>
#include <queue>
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
int fx, fy, sx, sy, ex, ey, t;

struct xy {
  int x, y;
  int level;
  xy(int x, int y, int level): x(x), y(y), level(level) {}
  xy() {}
};

void render() {
  for (int i = 0; i < 10; ++i) {
    cout << mp[i] << endl;
  }
}

int BFS() {
  queue<xy> q1, q2;
  q1.push(xy(fx, fy, 0));
  xy tmp1, tmp2;
  bool keep = true;
  while (!q1.empty()) {
    tmp1 = q1.front();
    if (tmp1.level == t && keep) {
      render();
      q2.push(xy(sx, sy, tmp1.level));
      keep = false;
    }
    if (!keep) {
      if (q2.empty()) break;
      tmp2 = q2.front();
      if (tmp2.x == ex && tmp2.y == ey) return tmp2.level;
      mp[tmp2.y][tmp2.x] = '-';
      if (tmp2.x + 1 < 17 && mp[tmp2.y][tmp2.x + 1] != '-' && mp[tmp2.y][tmp2.x + 1] != '*' && mp[tmp2.y][tmp2.x + 1] != '-') q2.push(xy(tmp2.x + 1, tmp2.y, tmp2.level + 1));
      if (tmp2.x - 1 >= 0 && mp[tmp2.y][tmp2.x - 1] != '-' && mp[tmp2.y][tmp2.x - 1] != '*' && mp[tmp2.y][tmp2.x - 1] != '-') q2.push(xy(tmp2.x - 1, tmp2.y, tmp2.level + 1));
      if (tmp2.y + 1 < 10 && mp[tmp2.y + 1][tmp2.x] != '-' && mp[tmp2.y + 1][tmp2.x] != '*' && mp[tmp2.y + 1][tmp2.x] != '-') q2.push(xy(tmp2.x, tmp2.y + 1, tmp2.level + 1));
      if (tmp2.y - 1 <= 0 && mp[tmp2.y - 1][tmp2.x] != '-' && mp[tmp2.y - 1][tmp2.x] != '*' && mp[tmp2.y - 1][tmp2.x] != '-') q2.push(xy(tmp2.x, tmp2.y - 1, tmp2.level + 1));
      q2.pop();
    }
    mp[tmp1.y][tmp1.x] = 'x';
    if (tmp1.x + 1 < 17 && mp[tmp1.y][tmp1.x + 1] != 'x') q1.push(xy(tmp1.x + 1, tmp1.y, tmp1.level + 1));
    if (tmp1.x - 1 >= 0 && mp[tmp1.y][tmp1.x - 1] != 'x') q1.push(xy(tmp1.x - 1, tmp1.y, tmp1.level + 1));
    if (tmp1.y + 1 < 10 && mp[tmp1.y + 1][tmp1.x] != 'x') q1.push(xy(tmp1.x, tmp1.y + 1, tmp1.level + 1));
    if (tmp1.y - 1 >= 0 && mp[tmp1.y - 1][tmp1.x] != 'x') q1.push(xy(tmp1.x, tmp1.y - 1, tmp1.level + 1));
    q1.pop();
  }
  return -1;
}

// int BFS(xy start) {
//   queue<xy> q;
//   q.push(start);
//   xy tmp;
//   while (true) {
//     if (tmp.x == ex && tmp.y == ey) return tmp.level;
//     if (tmp.x + 1 < 17 && mp[tmp.y][tmp.x + 1] != '-' && mp[tmp.y][tmp.x + 1] != '*') q.push(xy(tmp.x + 1, tmp.y, level + 1));
//     if (tmp.x - 1 >= 0 && mp[tmp.y][tmp.x - 1] != '-' && mp[tmp.y][tmp.x - 1] != '*') q.push(xy(tmp.x - 1, tmp.y, level + 1));
//     if (tmp.y + 1 < 10 && mp[tmp.y + 1][tmp.x] != '-' && mp[tmp.y + 1][tmp.x] != '*') q.push(xy(tmp.x, tmp.y + 1, level + 1));
//     if (tmp.y - 1 <= 0 && mp[tmp.y - 1][tmp.x] != '-' && mp[tmp.y - 1][tmp.x] != '*') q.push(xy(tmp.x, tmp.y - 1, level + 1));
//   }
//   return -1;
// }

int main() {
  cin >> fx >> fy;
  cin >> sx >> sy >> ex >> ey;
  cin >> t;
  int ans = BFS();
  if (ans == -1) cout << "Help!" << endl;
  else cout << ans << endl;
  return 0;
}
