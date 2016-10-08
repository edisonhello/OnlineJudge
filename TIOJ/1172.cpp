#include "lib1172.h"
#include <algorithm>
#include <iostream>
using namespace std;

int jizz[1000010];
int* __d;

void bs(int l, int r, int dl, int dr) {
  if (l == r) return;
  if (dl == dr) return;
  int dm = (dl + dr) / 2;
  nth_element(jizz + l, jizz + __d[dm], jizz + r + 1, comp);
  bs(l, __d[dm], dl, dm);
  bs(__d[dm] + 1, r, dm + 1, dr);
}

void query(int n, int D[], int l, int ans[]) {
  __d = D;
  for (int i = 0; i < n; ++i) jizz[i] = i;
  bs(0, n - 1, 0, l);
  for (int i = 0; i < l; ++i) {
    ans[i] = jizz[__d[i]];
  }
}
