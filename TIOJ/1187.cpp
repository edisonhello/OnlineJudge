#include <iostream>
#include <iomanip>
using namespace std;

double sm, n, mx, mn, x;

int main() {
  while (cin >> n) {
    if (n == 0) break;
    sm = 0;mx = 0; mn = 1e9;
    for (int i = 0; i < n; ++i) {
      cin >> x;
      sm += x;
      if (x > mx) mx = x;
      if (x < mn) mn = x;
    }
    cout << fixed << setprecision(2) << (sm - mn - mx) / (n - 2) << endl;
  }
  return 0;
}
