#include <iostream>
using namespace std;

long long A, B, C;
int ret;

int main() {
  cin >> A >> B >> C;
  ret = 1;
  for (; B; B /= 2) {
    if (B & 1) ret *= A, ret %= C;
    A *= A; A %= C;
  }
  cout << ret << endl;
  return 0;
}
