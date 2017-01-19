#include "lib1871.h"
#include <utility>
#include <cstdlib>
#define min(a, b) (a) < (b) ? (a) : (b)
using namespace std;

const int _maxn = 1000000 + 5, _LOG = 20;
int _N, _st[_LOG][_maxn], *_A, _Q;

int main() {
  _N = futa::init();
  _A = futa::momo_gives_you_list_of_futa();
  _Q = futa::momo_tells_you_q();
  for (int i = 0; i < _N; ++i) _st[0][i] = _A[i];
  for (int i = 1; (1 << i) <= _N; ++i) for (int j = 0; j + (1 << i) <= _N; ++j) _st[i][j] = min(_st[i - 1][j], _st[i - 1][j + (1 << (i - 1))]);
  while (_Q--) {
    pair<int, int> res = futa::momo_asks();
    int p = 31 - __builtin_clz(abs(res.first - res.second) + 1);
    futa::you_tell_momo(min(_st[p][res.first], _st[p][res.second - (1 << p) + 1]));
  }
  return 0;
}
