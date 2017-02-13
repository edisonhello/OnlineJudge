#include "lib1635.h"
#include <bits/stdc++.h>
using namespace std;

int N, ans;

int main() {
  N = Initialize();
  int L = 1, R = N;
  while (!ans) {
    if (R - L <= 3) {
      int a = L;
      for (int i = L + 1; i <= R; ++i) a = Max(a, i);
      ans = a;
      break;
    }
    int d = (R - L) / 3;
    int m1 = L + d, m2 = R - d;
    if (Max(m1, m2) == m1) R = m2;
    else L = m1;
  }
  Report(ans);
  return 0;
}
