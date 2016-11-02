#include <cstdio>
#include <queue>
#include <utility>
#include <set>
#define getchar getchar_unlocked
// #define x first
// #define y first
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
struct Jizz {
  int x, y, cnt;
};

int M, N, X, Y, Sx, Sy, Ex, Ey, ans;
queue<Jizz> q;
bool v[1005][1005];
bool b[1005][1005];
Jizz p;
int dx[] = {1, 0, -1, 0}; int dy[] = {0, 1, 0, -1};

int main() {
  rit(M, N);
  for (int i = 0; i < N; ++i) {
    rit(X, Y);
    // st.insert(make_pair(X, Y));
    b[X][Y] = true;
  }
  rit(Sx, Sy, Ex, Ey);
  q.push({ Sx, Sy, 0 });
  ans = -1;
  while (!q.empty()) {
    p = q.front(), q.pop();
    if (p.x == Ex && p.y == Ey) { ans = p.cnt; break; }
    for (int i = 0; i < 4; ++i) {
      if (p.x + dx[i] >= 1 && p.x + dx[i] <= M && p.y + dy[i] >= 1 && p.y + dy[i] <= M) {
        if (!v[p.x + dx[i]][p.y + dy[i]] && !b[p.x + dx[i]][p.y + dy[i]]) {
          v[p.x + dx[i]][p.y + dy[i]] = true; q.push({ p.x + dx[i], p.y + dy[i], p.cnt + 1 });
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
