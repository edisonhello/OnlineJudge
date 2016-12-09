#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, pre[105], A[105], dpa[105][105], delta;
int dp(int, int);
int sum(int, int);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  while (cin >> N, N) {
    for (int i = 0; i < N; ++i) cin >> A[i], pre[i] = pre[i - 1] + A[i];
    memset(dpa, 0, sizeof(dpa));
    cout << 2 * dp(0, N - 1) - pre[N - 1] << endl;
  }
}

int dp(int L, int R) {
  // if (L == R) return A[L];
  if (dpa[L][R]) return dpa[L][R];
  int m = 0;
  for (int k = L + 1; k <= R; ++k) m = min(m, dp(k, R));
  for (int k = L; k < R; ++k) m = min(m, dp(L, k));
  return dpa[L][R] = pre[R] - pre[L - 1] - m;
}
