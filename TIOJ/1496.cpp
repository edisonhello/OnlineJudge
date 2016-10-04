#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int m;
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> m;
  string a = "a", b = "b";
  for (int i = 0; i < sqrt(2 * m); ++i) {
    string at = a + b; string bt = b + a;
    a = at, b = bt;
  }
  cout << a << endl;
  cout << b << endl;
  return 0;
}
