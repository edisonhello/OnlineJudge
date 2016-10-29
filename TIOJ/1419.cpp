#include <iostream>
#include <algorithm>
using namespace std;

struct Jizz {
  int d, h;
};

int n, x, y, h, mx, mxH;

Jizz jizz[100005];

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y >> h;
    jizz[i].d = x * x + y * y;
    jizz[i].h = h;
  }
  sort(jizz, jizz + n, [](const Jizz& a, const Jizz& b) -> bool { return a.d < b.d; });
  mx = 0; mxH = 0;
  for (int i = 1; i < n; ++i) {
    if (jizz[i - 1].h > mxH) mxH = jizz[i - 1].h;
    if (mxH - jizz[i].h > mx) mx = mxH - jizz[i].h;
  }
  cout << mx << endl;
  return 0;
}
