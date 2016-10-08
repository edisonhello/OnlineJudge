#include <iostream>
using namespace std;

int t, m, k, a[510], sm, target, cur, cnt;

int main() {
  cin >> t;
  while (t--) {
    sm = 0;
    cin >> m >> k;
    for (int i = 0; i < m; ++i) cin >> a[i], sm += a[i];
    target = sm / k;
    cur = 0;
    cnt = 0;
    for (int i = 0; i < m; ++i) {
      cur += a[i];
      if (cnt > k - 1) cout << a[i] << ' ';
      else if (cur > target) {cnt++; cur = 0; cout << "/ "; i--;}
      else cout << a[i] << ' ';
    }
  }
  return 0;
}
