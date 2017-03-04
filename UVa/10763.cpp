#include <bits/stdc++.h>
using namespace std;

multiset<pair<int, int>> s;
int n;

int main() {
  while (cin >> n, n) {
    s.clear();
    int a, b;
    for (int i = 0; i < n; ++i) cin >> a >> b, s.insert(make_pair(a, b));
    int osas = 1;
    for (pair<int, int> p : s) {
      if (osas != 1) break;
      if (s.count(make_pair(p.second, p.first)) != s.count(p)) osas = 0;
    }
    if (osas) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}
