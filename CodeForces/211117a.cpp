#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, A, tot;

signed main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> A, tot += A;
  if (tot > m * 60) cout << "NO\n";
  else cout << "YES\n";
  return 0;
}
