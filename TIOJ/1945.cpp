#include "lib1945.h"
#include <iostream>
using namespace std;

const int maxn = (1 << 17);
int query[maxn], ans[maxn], Xor[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  Init();
  for (int i = 0; i < maxn; ++i) {
    query[0] = i;
    ans[i] = Query(1, query);
    Xor[i] = Xor[i - 1] ^ ans[i];
  }
  int L = 0, R = maxn - 1;
  while (L < R) {
    int M = (L + R) >> 1;
    for (int i = L; i <= M; ++i) query[i - L] = i;
    int q = Query(M - L + 1, query);
    if (q ^ (Xor[M] ^ Xor[L - 1])) R = M;
    else L = M + 1;
  }
  query[0] = L;
  int a = Query(1, query), b = Query(1, query);
  int T = 0, F = 0;
  if (ans[L]) T++; else F++;
  if (a) T++; else F++;
  if (b) T++; else F++;
  if (T > F) ans[L] = 1;
  else ans[L] = 0;
  for (int i = 0; i < maxn; ++i) cout << ans[i] << ' ';
  cout << '\n';
  return 0;
}
