#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[31][31];
int a[31], b[31];
int n;
int dpdp(int, int);

int main() {
  while (cin >> n, n) {
    for (int i = 0; i < n; ++i) {cin >> b[i]; a[i] = a[i - 1] ^ b[i];}
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
    memset(dp, 0, sizeof(dp));
    cout << dpdp(0, n) << endl;
  }
}

int dpdp(int l, int r) {
  if (dp[l][r]) return dp[l][r];
  int mx = 0;
  for (int i = l; i < r; ++i) {
    mx = max(max(mx, dpdp(l, i) + dpdp(i + 1, r) + a[i - 1] ^ a[l] ^ a[r] ^ a[i]), b[i]);
  }
  return dp[l][r] = mx;
}
