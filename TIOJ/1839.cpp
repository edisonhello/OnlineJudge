#include "lib1839.h"
using namespace std;

int n, s[5005], d[5005], ret1, l, r, m, ret2;
bool jizz[5005];

int main() {
  n = Initialize();
  ret1 = tryCombination(s);
  for (int i = 0; i < n; ++i) {
    l = 0; r = n;
    m = (l + r) >> 1;
    while (l + 1 != r) {
      for (int j = l; j < m; ++j) {
        if (!jizz[j]) s[j] = !s[j];
      }
      ret2 = tryCombination(s);
      if (ret1 != ret2 && (ret1 == i || ret2 == i)) r = m;
      else l = m;
      ret1 = ret2;
      m = (l + r) >> 1;
    }
    jizz[l] = true; d[l] = i;
    if (ret1 == i) s[l] = !s[l], ret1 = tryCombination(s);
  }
  answer(s, d);
  return 0;
}
