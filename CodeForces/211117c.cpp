#include <bits/stdc++.h>
#define RAD(x) (x * acos(-1) / 180)
using namespace std;

int A1, C1, A2, C2;
char B1, D1, B2, D2;

int main() {
  cin >> A1 >> B1 >> C1 >> D1;
  cin >> A2 >> B2 >> C2 >> D2;
  double p1 = D1 == 'N' ? C1 : -C1, p2 = D2 == 'N' ? C2 : -C2;
  double l1 = B1 == 'E' ? A1 : -A1, l2 = B2 == 'E' ? A2 : -A2;
  double d = acos(sin(RAD(p1)) * sin(RAD(p2)) + cos(RAD(p1)) * cos(RAD(p2)) * cos(RAD(fabs(l1 - l2))));
  cout << fixed << setprecision(10) << d << '\n';
  return 0;
}
