#include <iostream>
using namespace std;

int n, x, y;
int main() {
  cin >> n;
  x = 1; y = 1;
  for (int i = 1; i < n; ++i) {
    if (i % 2) x += y;
    else y += x;
  }
  if (n % 2) cout << y << endl;
  else cout << x << endl;
  return 0;
}
