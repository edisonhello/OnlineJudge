#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> n >> m) {
    if (n == 1) cout << "0\n\n";
    else if (m % (n - 1) == 0) {
      cout << n - 2 << '\n';
      for (int i = 2; i <= n - 1; ++i) cout << i << ' ';
      cout << '\n';
    } else {
      cout << 0 << "\n\n";
    }
  }
  return 0;
}
