#include <bits/stdc++.h>
using namespace std;

int n, a[3], b[3];

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    if (a[i] < b[i]) swap(a[i], b[i]);
  }
  if (n == 1) {
    if (a[0] == b[0]) return cout << "YES\n", 0;
    else return cout << "NO\n", 0;
  }
  if (n == 2) {
    if (a[0] == a[1]) if (b[0] + b[1] == a[0]) return cout << "YES\n", 0;
    return cout << "NO\n", 0;
  }
  if (n == 3) {
    if (a[0] == a[1] && a[1] == a[2]) if (b[0] + b[1] + b[2] == a[0]) return cout << "YES\n", 0;
    if (a[1] == a[2] && b[1] + b[2] == a[0] && b[0] + a[2] == a[0]) return cout << "YES\n", 0;
    if (a[2] == a[0] && b[2] + b[0] == a[1] && b[1] + a[0] == a[1]) return cout << "YES\n", 0;
    if (a[0] == a[1] && b[0] + b[1] == a[2] && b[2] + a[1] == a[2]) return cout << "YES\n", 0;
    return cout << "NO\n", 0;
  }
  return 0;
}
