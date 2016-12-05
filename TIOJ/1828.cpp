#include <iostream>
#include <cmath>
using namespace std;

int T;
double t, z, x, y, d;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> x >> y >> z;
    if (x == 0) { cout << -1 << endl; continue; }
    d = 10000 - x;
    t = 10000 / z;
    if ((int)(d / (t + y)) == ceil(d / (t + y))) cout << (int)(d / (t + y)) + 1 << endl;
    else cout << ceil(d / (t + y)) << endl;
  }
  return 0;
}
