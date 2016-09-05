#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
  long long int n;
  while (cin >> n) {
    if (n == 0) break;
    if (sqrt(n) == (long long int)sqrt(n)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  return 0;
}
