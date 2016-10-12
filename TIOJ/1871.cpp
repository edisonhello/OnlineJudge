#include "lib1871.h"
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int N, i, q;
int *A;
pair<int, int> ask;

int main() {
  N = futa::init();
  A = futa::momo_gives_you_list_of_futa();
  vector<int> jizz;
  for (i = 0; i < N; ++i) jizz.push_back(A[i]);
  q = futa::momo_tells_you_q();
  for (i = 0; i < q; ++i) {
    ask = futa::momo_asks();
    auto mm = minmax_element(jizz.begin() + ask.first, jizz.begin() + ask.second + 1);
    futa::you_tell_momo(*(mm.second));
  }
  return 0;
}
