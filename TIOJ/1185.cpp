#include <iostream>
using namespace std;

long long int a, b, c;

int main() {
  while (cin >> a >> b >> c) {
    if (a + b > c && b + c > a && a + c > b) {
      cout << "SAFE" << endl;
    } else {
      cout << "BYE" << endl;
    }
  }
  return 0;
}
