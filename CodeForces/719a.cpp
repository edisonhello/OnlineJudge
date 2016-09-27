#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[92];
  if (n == 1) {cout << -1 << endl; return 0;}
  for (int i = 0; i < n; ++i) cin >> a[i];
  if (a[n - 1] - a[n - 2] > 0) cout << "UP" << endl;
  else cout << "DOWN" << endl;
  return 0;
}
