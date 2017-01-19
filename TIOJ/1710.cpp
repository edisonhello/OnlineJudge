#include <iostream>
#include <algorithm>
#define abs(x) (x) > 0 ? (x) : (-x)
using namespace std;

const int maxn = 50000 + 5;
int T, N, A[maxn];
long long ans;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    ans = 0;
    for (int i = 0; i < N; ++i) {
      int Min = A[i], Max = A[i];
      for (int j = i + 1; j < N; ++j) {
        Min = min(A[j], Min);
        Max = max(A[j], Max);
        if (j - i == abs(A[j] - A[i]) && max(A[i], A[j]) == Max && min(A[i], A[j]) == Min) ans += j - i - 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
