#include <iostream>
#include <cmath>
using namespace std;

int N, kase;

int main() {
  while (cin >> N, N >= 0) {
    cout << "Case " << ++kase << ": " << ceil(log2(N)) << '\n';
  }
  return 0;
}
