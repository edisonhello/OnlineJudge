#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int s, x1, x2, t1, t2, p, d;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> s >> x1 >> x2;
  cin >> t1 >> t2;
  cin >> p >> d;
  if (t2 <= t1) { cout << (double)abs(x1 - x2) / (double)(t2) << '\n'; return 0; }
  if (d * (x2 - x1) > 0) {
    
  } else {

  }
  return 0;
}
