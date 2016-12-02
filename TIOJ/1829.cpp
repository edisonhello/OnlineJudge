#include <iostream>
using namespace std;

int N, K, A, B, T;
const int MOD = 1e8 + 7;
int __pow(int, int);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> N >> K >> A >> B:

  }
}

int __pow(int base, int p) {
  int ret = 1;
  for (; p; p /= 2) {
    if (p & 1) ret *= base, ret %= MOD;
    base *= base; base %= MOD;
  }
  return ret;
}
