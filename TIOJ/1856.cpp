#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int A[maxn], T, N;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A, A + N);
    int k = 1, ans = 0;
    for (int i = N - 1; i >= 0; --i) {
      if (A[i] - k > 0) ans += A[i] - k, k++;
      else break;
    }
    cout << ans << '\n';
  }
  return 0;
}
