#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;


int a[10000], b[10000], c[10000], n;
void ts();

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i] >> c[i];
  }
  ts();
}


void ts() {
  double r = 129600;
  double l = 0;
  double m2 = (l + r * 2) / 3;
  double m1 = (l * 2 + r) / 3;
  double v1 = 1e9, v2 = 1e9;
  while (true) {
    if (abs(r - l) < 0.0000001) {printf("%.6f\n", r); return;}
    v1 = 1e9, v2 = 1e9;
    for (int i = 0; i < n; ++i) {
      v1 = min(v1, a[i] * m1 * m1 + b[i] * m1 + c[i]);
      v2 = min(v2, a[i] * m2 * m2 + b[i] * m2 + c[i]);
    }
    if (v1 > v2) r = m2;
    else l = m1;
    m1 = (l * 2 + r) / 3;
    m2 = (l + r * 2) / 3;
  }
}
