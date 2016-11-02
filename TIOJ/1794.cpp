#include <cstdio>
#include <bitset>
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

bitset<3005> v[3005];
int n, m, x[3005][3005], mx;
short di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
void DFS(int, int, int, int);

int main() {
  rit(n, m);
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) rit(x[i][j]);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!v[i][j]) {
        // printf("i: %d j: %d\n", i, j);
        v[i][j] = true;
        DFS(i, j, x[i][j], 1);
      }
    }
  }
  printf("%d\n", mx);
  return 0;
}

void DFS(int i, int j, int xx, int nw) {
  if (nw > mx) mx = nw;
  for (int _ = 0; _ < 4; ++_) {
    if (i + di[_] < n && i + di[_] >= 0 && j + dj[_] < m && j + dj[_] >= 0) {
      if (!v[i + di[_]][j + dj[_]] && x[i + di[_]][j + dj[_]] == xx) {
        v[i + di[_]][j + dj[_]] = true;
        DFS(i + di[_], j + dj[_], xx, nw + 1);
      }
    }
  }
  if (nw > mx) mx = nw;x
}
