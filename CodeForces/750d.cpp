#include <iostream>
#include <utility>
#define int long long
using namespace std;

const int maxw = 10000;
bool v[maxw][maxw];
pair<int, int> st[maxw][maxw];
int t[35], n;

int solve(int, int, int, int, int, int);
pair<pair<int, int>, pair<int, int>> trans(int, int);
int id(int, int);

signed main() {
  cin >> n;
  for (int i = 0; i < maxw; ++i) for (int j = 0; j < maxw; ++j) st[i][j].first = (1 << 8);
  for (int i = 0; i < n; ++i) cin >> t[i];
  cout << solve(maxw / 2, maxw / 2, 1, 0, 0, 1) << '\n';
  return 0;
}

int solve(int x, int y, int sx, int sy, int dep, int c) {
  cout << x << ' ' << y << ' ' << sx << ' ' << sy << ' ' << dep << ' ' << c << '\n';
  if (dep >= n) return 0;
  int ret = (!v[x][y]);
  v[x][y] = true;
  auto jizz = trans(sx, sy);
  if (c == t[dep] && (((1 << id(jizz.first.first, jizz.first.second) & st[x][y].first))) || t[dep + 1] > st[x][y].second) ret += solve(x + jizz.first.first, y + jizz.first.second, jizz.first.first, jizz.first.second, dep + 1, 1), st[x][y].second = max(st[x][y].second, t[dep + 1]), st[x][y].first ^= id(jizz.first.first, jizz.first.second);
  if (c == t[dep] && (((1 << id(jizz.second.first, jizz.second.second) & st[x][y].first))) || t[dep + 1] > st[x][y].second) ret += solve(x + jizz.second.first, y + jizz.second.second, jizz.second.first, jizz.second.second, dep + 1, 1), st[x][y].second = max(st[x][y].second, t[dep + 1]), st[x][y].first ^= id(jizz.second.first, jizz.second.second);
  if (c != t[dep]) ret += solve(x + sx, y + sy, sx, sy, dep, c + 1);
  return ret;
}

pair<pair<int, int>, pair<int, int>> trans(int sx, int sy) {
  if (sx && sy == 0) return make_pair(make_pair(sx, -1), make_pair(sx, 1));
  if (sx == 0 && sy) return make_pair(make_pair(-1, sy), make_pair(1, sy));
  return make_pair(make_pair(sx, 0), make_pair(0, sy));
}

int id(int x, int y) {
  if (x == 0) {
    if (y == 1) return 1;
    // if (y == 0) return 2;
    if (y == -1) return 2;
  }
  if (x == 1) {
    if (y == 1) return 3;
    if (y == 0) return 4;
    if (y == -1) return 5;
  }
  if (x == -1) {
    if (y == 1) return 6;
    if (y == 0) return 7;
    if (y == -1) return 8;
  }
}
