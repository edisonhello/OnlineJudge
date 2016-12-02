#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int M, N, K, X, Y, X1, Y1, X2, Y2, ans;
short dx[] = {5, 0, -5, 0}, dy[] = {0, 5, 0, -5};
bool v[1200][1200];

struct Node {
  int x, y, len;
};

queue<Node> q;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  while (cin >> M >> N >> K) {
    if (!M && !N && !K) break;
    memset(v, false, sizeof(v));
    while (K--) {
      cin >> X >> Y; v[X][Y] = true;
    }
    cin >> X1 >> Y1 >> X2 >> Y2;
    while (q.size()) q.pop();
    q.push((Node){ X1, Y1, 0 });
    while (q.size()) {
      Node node = q.front(); q.pop();
      if (node.x == X2 && node.y == Y2) { ans = node.len; break; }
      for (int i = 0; i < 4; ++i) {
        if (node.x + dx[i] < M && node.x + dx[i] >= 0 && node.y + dy[i] < N && node.y + dy[i] >= 0) {
          if (!v[node.x + dx[i]][node.y + dy[i]]) {
            v[node.x + dx[i]][node.y + dy[i]] = true;
            q.push((Node){ node.x + dx[i], node.y + dy[i], node.len + 1 });
          }
        }
      }
    }
    if (ans) cout << ans << endl;
    else cout << "No way\n";
  }
  return 0;
}
