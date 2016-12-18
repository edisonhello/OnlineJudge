#include <iostream>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;

int T, N, A[100005], ans;

signed main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A, A + N);
    ans = 0;
    if (N & 1) for (int i = 1; i < N; i += 2) ans += A[i] + A[i + 1] - abs(A[i] - A[i + 1]);
    else for (int i = 0; i < N; i += 2) ans += A[i] + A[i + 1] - abs(A[i] - A[i + 1]);
    cout << ans * 2 << '\n';
  }
  return 0;
}
