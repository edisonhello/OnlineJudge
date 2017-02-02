#include <bits/stdc++.h>
using namespace std;

long long L[10000010], R[10000010], lL, lR, T, n, k, l, D[10000010], mid, i, __t;
long long ans, tmp;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> k >> l;
  for (i = 0; i < n; ++i) cin >> D[i];
  mid = 0;
  while (mid < n && D[mid] <= l / 2) {
    R[mid + 1] = 2 * D[mid];
    if (mid + 1 - k > 0) R[mid + 1] += R[mid + 1 - k];
    mid++;
  }
  for (i = 0; i < n - mid; ++i) {
    L[i + 1] = 2 * (l - D[n - i - 1]);
    if (i + 1 - k > 0) L[i + 1] += L[i + 1 - k];
  }
  ans = R[mid] + L[n - mid];
  for (i = 0; i < k + 1; ++i) {
    tmp = l;
    if (mid - i > 0) tmp += R[mid - i];
    if (n - mid + i - k > 0) tmp += L[n - mid + i - k];
    if (tmp < ans) ans = tmp;
  }
  cout << ans << '\n';
  return 0;
}
