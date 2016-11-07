#include <cstdio>
#include <bitset>
#include <queue>
#include <utility>
#define x first
#define y second
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

// struct s {
//   int i, j,
// };

bitset<3005> v[3005];
int n, m, x[3005][3005], mx, bfs, t, ret;
pair<int, int> p;
short di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
int BFS(int, int);

int main() {
  rit(n, m);
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) rit(x[i][j]);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!v[i][j]) {
        bfs = BFS(i, j);
        if (bfs > mx) mx = bfs;
      }
    }
  }
  printf("%d\n", mx);
  return 0;
}

int BFS(int i, int j) {
  queue<pair<int, int>> q;
  t = x[i][j];
  q.push(make_pair(i, j));
  ret = 0;
  while (q.size()) {
    p = q.front(); q.pop();
    for (int _ = 0; _ < 4; ++_) {
      if (p.x + di[_] < n && p.x + di[_] >= 0 && p.y + dj[_] < m && p.y + dj[_] >= 0) {
        if (!v[p.x + di[_]][p.y + dj[_]] && x[p.x + di[_]][p.y + dj[_]] == t) {
          v[p.x + di[_]][p.y + dj[_]] = true;
          q.push(make_pair(p.x + di[_], p.y + dj[_]));
          ret++;
        }
      }
    }
  }
  return ret;
}
