#include <iostream>
#include <algorithm>
using namespace std;

int a[500], t, r, dis;

int main() {
  cin >> t;
  while (t--) {
    cin >> r;
    for (int i = 0; i < r; ++i) cin >> a[i];
    sort(a, a + r);
    dis = 0;
    for (int i = 0; i < r / 2; ++i) {
      dis += abs(a[r - i - 1] - a[i]);
    }
    cout << dis << endl;
  }
  return 0;
}
