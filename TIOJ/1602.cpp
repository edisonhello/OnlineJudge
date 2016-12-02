#include <cstdio>
#include <queue>
#include <set>
#include <utility>
#include <algorithm>
#define getchar getchar_unlocked
using namespace std;

char __c;
bool flag;

template <typename T>
inline bool rit(T& x) {
  __c = 0, flag = false;
  while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
  __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
  while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
  if (flag) x = -x;
  return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

bool can[1505][1505];
int h[1505][1505], n, m, sx, sy;
short dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}, cnt[1505][1505];

struct Node {
  int x, y, px, py;
};

queue<Node> q;
set<pair<int, int>> ans;

int main() {
  rit(n, m);
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) rit(h[i][j]);
  rit(sx, sy);
  q.push((Node){ sx, sy, sx, sy }); can[sy][sx] = true;
  while (q.size()) {
    Node node = q.front(); q.pop();
    if (h[node.y][node.x] >= h[node.py][node.px] && can[node.py][node.px]) {
      can[node.y][node.x] = true;
      ans.insert({ node.x, node.y });
    }
    for (int i = 0; i < 4; ++i) {
      if (node.x + dx[i] < m && node.x + dx[i] >= 0 && node.y + dy[i] < n && node.y + dy[i] >= 0) {
        if (cnt[node.y + dy[i]][node.x + dx[i]] < 4) {
          cnt[node.y + dy[i]][node.x + dx[i]]++;
          q.push((Node){ node.x + dx[i], node.y + dy[i], node.x, node.y});
        }
      }
    }
  }
  for (auto i : ans) printf("(%d,%d)\n", i.first, i.second);
  return 0;
}
