#include <iostream>
#include <vector>
#include <utility>
#include <vector>
#define INF 1 << 15
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
inline bool rit(T& x, Args& ...args) {return rit(x) && rit(args...);}

int n, q, x0, y0, x1, y1;
int mp[21][21];

struct Point {
  int i, j;
  Point(int i, int j): x(i), y(j) {}
  Point() {}
};

typedef pair<Point, int> PR;
vector<PR> G[21][21];
void graph();
int dp[21][21][21][21][21][21];
int Floyd_Warshell(int, int, int, int);

int main() {
  rit(n);
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) rit(mp[i][j]);
  graph();
  rit(q);
  while (q--) {
    rit(x0, y0, x1, y1);
    dpdp();
    mx = INF;
    cout << mp[y0][x0] + Floyd_Warshell(y0, x0, y1, x1) << endl;
  }
}

void graph() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i + 1 < n) G[i][j].push_back(PR(Point(i + 1, j)), mp[i + 1][j]);
      if (i - 1 >= 0) G[i][j].push_back(PR(Point(i - 1, j)), mp[i - 1][j]);
      if (j + 1 < n) G[i][j].push_back(PR(Point(i, j + 1)), mp[i][j + 1]);
      if (j - 1 >= 0) G[i][j].push_back(PR(Point(i, j - 1)), mp[i][j - 1]);
    }
  }
}

int Floyd_Warshell(int i1, int j1, int i2, int j2) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (dp[i1][j1][i2][j2][i][j] < mn) mn = dp[i1][j1][i2][j2][i][j];
    }
  }
}

void dpdp() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int ii = 0; ii < n; ++ii) {
        for (int jj = 0; jj < n; ++jj) {
          for (int k = 0; k < G[i][j])
        }
      }
    }
  }
}
