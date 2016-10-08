#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#define tp tuple<int, int, int, int>
using namespace std;

int k, m, n, h[100][100], dir[8] = {1, 0, -1, 0, 0, 1, 0, -1};
bool v[100][100];
int BFS();
tp tmp;

int main() {
  cin >> k;
  while (k--) {
    cin >> m >> n;
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) cin >> h[i][j];
    memset(v, false, sizeof(v));
    cout << BFS() << endl;
  }
  return 0;
}

int BFS() {
  queue<tp> q;
  q.push(tp(0, 0, 0));
  v[0][0] = true;
  while (!q.empty()) {
    tmp = q.front(); q.pop();
    if (get<0>(tmp) == n - 1 && get<1>(tmp) == m - 1) return get<2>(tmp);
    for (int i = 0; i < 4; ++i) {
      if (get<0>(tmp) + dir[i * 2] >= 0 && get<0>(tmp) + dir[i * 2] < n && get<1>(tmp) + dir[i * 2 + 1] >= 0 && get<1>(tmp) + dir[i * 2 + 1] < m && !v[get<1>(tmp) + dir[i * 2 + 1]][get<0>(tmp) + dir[i * 2]]) {
        if (abs(h[get<1>(tmp)][get<0>(tmp)] - h[get<1>(tmp) + dir[i * 2 + 1]][get<0>(tmp) + dir[i * 2]]) <= 5) {
          v[get<1>(tmp) + dir[i * 2 + 1]][get<0>(tmp) + dir[i * 2]] = true;
          q.push(tp(get<0>(tmp) + dir[i * 2], get<1>(tmp) + dir[i * 2 + 1], get<2>(tmp) + 1));
        }
      }
    }
  }
}
