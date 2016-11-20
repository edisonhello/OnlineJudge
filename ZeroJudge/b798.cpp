#include <cstdlib>
#include <iostream>
using namespace std;

int a, b, c, d, x;

int main() {
  srand(11111);
  cin >> a >> b >> c >> d;
  x = rand() * rand() % 2;
  if (a + b + c + d < 2000) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}
