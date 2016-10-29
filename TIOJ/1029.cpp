#include <iostream>
#include <algorithm>
using namespace std;

int n, a[1005], dpa[1005][1005], tot, ans;
int dp(int, int);

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i], tot += a[i];
  ans = dp(0, n - 1);
  cout << (tot - ans) / 2 + ans << ' ' << (tot - ans) / 2 << endl;
  return 0;
}

int dp(int L, int R) {
  if (L == R) return a[L];
  if (L > R) return 0;
  if (dpa[L][R]) return dpa[L][R];
  return dpa[L][R] = max(a[L] - dp(L + 1, R), a[R] - dp(L, R - 1));
}
