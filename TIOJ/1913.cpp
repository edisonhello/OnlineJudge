#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int T, N, A[5005], ans;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> N; ans = 0;
    for (int i = 1; i <= N; ++i) cin >> A[i];
    for (int i = 1; i <= N; ++i) {
      int Max = A[i], Min = A[i];
      for (int j = i + 1; j <= N; ++j) {
        Max = max(Max, A[j]);
        Min = min(Min, A[j]);
        if (abs(A[j] - A[i]) == j - i && Max == max(A[i], A[j]) && Min == min(A[i], A[j])) ans++;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
