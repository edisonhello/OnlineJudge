#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

struct TP {
  int x, y, z;
  bool o, t, th;
  TP(int x, int y, int z, bool o, bool t, bool th): x(x), y(y), z(z), o(o), t(t), th(th) {}
  TP() {}
};

int n, x1, y1, z1, x2, y2, z2;
void BFS();
TP t;

int main() {
  while (cin >> n >> x1 >> y1 >> z1 >> x2 >> y2 >> z2, n) {
    BFS();
  }
  return 0;
}

void BFS() {
  queue<TP> q;
  q.push(TP(x1, y1, z1, false, false, false));
  while (q.size()) {
    t = q.front(), q.pop();
    if (t.x == x2 && t.y == y2 && t.z == z2) {cout << "Yes\n"; return;}
    if (!t.o) q.push(TP(t.y, t.x, t.z, true, t.t, t.th));
    if (!t.t) q.push(TP(t.x, t.z, t.y, t.o, true, t.th));
    if (!t.th) q.push(TP(t.z, t.y, t.x, t.o, t.t, true));
    if (2 * t.y - t.x + 1 <= n && 2 * t.x - t.y - 1 <= n && t.z <= n) q.push(TP(2 * t.y - t.x + 1, 2 * t.x - t.y - 1, t.z, t.o, t.t, t.th));
  }
  cout << "No\n";
}
