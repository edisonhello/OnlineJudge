#include <iostream>
#include <cmath>
using namespace std;

long long n, t, px, py, x, y, vx, vy;
bool ans;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  while (cin >> n >> t >> px >> py) {
    if (!n && !t && !px && !py) break;
    ans = false;
    for (int i = 0; i < n; ++i) {
      cin >> x >> y >> vx >> vy;
      if (ans) continue;
      vx = x + t * vx; vy = y + t * vy;
      x = x - px; y = y - py;
      vx = vx - px; vy = vy - py;
      if (x * vy - y * vx == 0 && x * vx + y * vy <= 0) ans = true;
    }
    if (ans) cout << "true\n";
    else cout << "false\n";
  }
  return 0;
}
