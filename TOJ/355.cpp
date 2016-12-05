#include <iostream>
using namespace std;

int n, k, a, mx, mx2;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n >> k;
  cin >> a; mx = a;
  cin >> a; mx2 = a;
  if (mx2 > mx) swap(mx, mx2);
  for (int i = 2; i < n; ++i) {
    cin >> a;
    if (a > mx) mx2 = mx, mx = a;
    else if (a > mx2) mx2 = a;
  }
  cout << mx2 << '\n';
  return 0;
}
