#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 50000 + 5;
int D[maxn], L, N, M, l, r;
vector<int> d;

bool check(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> L >> N >> M;
  for (int i = 1; i <= N; ++i) cin >> D[i];
  D[0] = 0;
  sort(D, D + N + 1);
  int l = 0, r = L;
  while (l < r) {
    int m = (l + r) >> 1;
    if (check(m)) l = m + 1;
    else r = m;
  }
  cout << l << '\n';
}

bool check(int len) {
  int rock = 0, s = 0;
  for (int i = 1; i <= N; ++i) {
    if (D[i] - D[s] < len) rock++;
    else s = i;
  }
  if (L - D[s] < len && s) ++rock;
  if (L - D[s] < len && !s) return false;
  return rock < M;
}
