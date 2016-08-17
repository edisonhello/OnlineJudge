#include <cstdio>
#include <queue>
#include <deque>
#include <cstring>
#include <string>
using namespace std;

int maze[1000][1000];

struct Edge {
  int from, to;
  int w;
  bool operator<(const Edge& e) const {
    return e.w < w;
  }
};

deque<Edge> G[1000000];
bool v[1000000];
int dis[1000000];

int main() {
  int N;
  int n, m;
  Edge tmp, pqEdge;
  cin >> N;
  for (int no = 0; no < N; ++no) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> maze[i][j];
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i - 1 >= 0 && j - 1 >= 0) {
          tmp.from = maze[i][j];
          tmp.to = maze[i - 1][j];
          tmp.w =
        }
        if (i - 1 >= 0 && j + 1 < m) {

        }
        if (i + 1 < n && j - 1 >= 0) {

        }
        if (i + 1 < n && j + 1 < m) {

        }
      }
    }
  }
}
