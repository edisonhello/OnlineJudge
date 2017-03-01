#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000 + 5, MOD = 1000000007;
int l, r;

int main() {
  cin >> l >> r;
  if (l != -r) return cout << "0\n", 0;
  if (r & 1) return cout << "0\n", 0;
  int ret = 1;
  for (int i = r / 2 + 1; i <= r; ++i) ret = ((long long)ret * (long long)i) % MOD;
  cout << ret << '\n';
  return 0;
}
