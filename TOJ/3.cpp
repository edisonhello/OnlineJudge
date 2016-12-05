#include <iostream>
#include <algorithm>
using namespace std;

int T, a, b;

int main() {
  cin >> T;
  while (T--) {
    cin >> a >> b;
    cout << __gcd(a, b) << endl;
  }
  return 0;
}
