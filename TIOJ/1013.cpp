#include <iostream>
#include <string>
#include <queue>
#include <tuple>
#define tp tuple<int, int, int>
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

int fx, fy, sx, sy, ex, ey, t, tm;
tp tmp;
bool v[20][20];
void output();

int BFS() {
  queue<tp> q1, q2;
  q1.push(tp(fy, fx, 1));
  while (!q1.empty() && get<2>(q1.front()) < t) {
    tmp = q1.front(); q1.pop();
    // cout << get<0>(tmp) << ' ' << get<1>(tmp) << " jizz" << endl;
    if (get<0>(tmp) >= 0 && get<0>(tmp) < 10 && get<1>(tmp) >= 0 && get<1>(tmp) < 17) {
      mp[get<1>(tmp)][get<0>(tmp)] = 'x';
      if (get<0>(tmp) + 1 < 10 && mp[get<1>(tmp)][get<0>(tmp) + 1] != 'x') q1.push(tp(get<0>(tmp) + 1, get<1>(tmp), get<2>(tmp) + 1));
      if (get<0>(tmp) - 1 >= 0 && mp[get<1>(tmp)][get<0>(tmp) - 1] != 'x') q1.push(tp(get<0>(tmp) - 1, get<1>(tmp), get<2>(tmp) + 1));
      if (get<1>(tmp) + 1 < 17 && mp[get<1>(tmp) + 1][get<0>(tmp)] != 'x') q1.push(tp(get<0>(tmp), get<1>(tmp) + 1, get<2>(tmp) + 1));
      if (get<0>(tmp) - 1 >= 0 && mp[get<1>(tmp) - 1][get<0>(tmp)] != 'x') q1.push(tp(get<0>(tmp), get<1>(tmp) - 1, get<2>(tmp) + 1));
    }
  }
  // output();
  q2.push(tp(sy, sx, t));
  v[sx][sy] = true;
  tm = t;

  while (true) {
    while (!q1.empty() && get<2>(q1.front()) == tm) {
      tmp = q1.front(); q1.pop();
      // cout << get<0>(tmp) << ' ' << get<1>(tmp) << " jizz" << endl;
      if (get<0>(tmp) >= 0 && get<0>(tmp) < 10 && get<1>(tmp) >= 0 && get<1>(tmp) < 17) {
        mp[get<1>(tmp)][get<0>(tmp)] = 'x';
        if (get<0>(tmp) + 1 < 10 && mp[get<1>(tmp)][get<0>(tmp) + 1] != 'x') q1.push(tp(get<0>(tmp) + 1, get<1>(tmp), get<2>(tmp) + 1));
        if (get<0>(tmp) - 1 >= 0 && mp[get<1>(tmp)][get<0>(tmp) - 1] != 'x') q1.push(tp(get<0>(tmp) - 1, get<1>(tmp), get<2>(tmp) + 1));
        if (get<1>(tmp) + 1 < 17 && mp[get<1>(tmp) + 1][get<0>(tmp)] != 'x') q1.push(tp(get<0>(tmp), get<1>(tmp) + 1, get<2>(tmp) + 1));
        if (get<0>(tmp) - 1 >= 0 && mp[get<1>(tmp) - 1][get<0>(tmp)] != 'x') q1.push(tp(get<0>(tmp), get<1>(tmp) - 1, get<2>(tmp) + 1));
      }
    }
    // output();
    while (!q2.empty() && get<2>(q2.front()) == tm) {
      tmp = q2.front(); q2.pop();
      // cout << get<0>(tmp) << ' ' << get<1>(tmp) << ' ' << get<2>(tmp) << endl;
      if (get<0>(tmp) == ex && get<1>(tmp) == ey) return get<2>(tmp);
      if (get<0>(tmp) + 1 < 10 && !v[get<0>(tmp) + 1][get<1>(tmp)] && mp[get<0>(tmp) + 1][get<1>(tmp)] == '.') {
        v[get<0>(tmp) + 1][get<1>(tmp)] = true;
        q2.push(tp(get<0>(tmp) + 1, get<1>(tmp), get<2>(tmp) + 1));
      }
      if (get<0>(tmp) - 1 >= 0 && !v[get<0>(tmp) - 1][get<1>(tmp)] && mp[get<0>(tmp) - 1][get<1>(tmp)] == '.') {
        v[get<0>(tmp) - 1][get<1>(tmp)] = true;
        q2.push(tp(get<0>(tmp) - 1, get<1>(tmp), get<2>(tmp) + 1));
      }
      if (get<1>(tmp) + 1 < 17 && !v[get<0>(tmp)][get<1>(tmp) + 1] && mp[get<0>(tmp)][get<1>(tmp) + 1] == '.') {
        v[get<0>(tmp)][get<1>(tmp) + 1] = true;
        q2.push(tp(get<0>(tmp), get<1>(tmp) + 1, get<2>(tmp) + 1));
      }
      if (get<0>(tmp) - 1 >= 0 && !v[get<0>(tmp)][get<1>(tmp) - 1] && mp[get<0>(tmp)][get<1>(tmp) - 1] == '.') {
        v[get<0>(tmp)][get<1>(tmp) - 1] = true;
        q2.push(tp(get<0>(tmp), get<1>(tmp) - 1, get<2>(tmp) + 1));
      }
    }
    tm++;
    if (q2.empty()) return -1;
  }
}

void output() {
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 17; ++j) {
      cout << mp[i][j];
    }
    cout << endl;
  }
}
int main() {
  cin >> fx >> fy;
  cin >> t;
  cin >> sx >> sy >> ex >> ey;
  int ans = BFS();
  if (ans == -1) cout << "Help!" << endl;
  else cout << ans << endl;
  return 0;
}
