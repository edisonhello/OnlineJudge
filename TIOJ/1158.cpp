#include <iostream>
using namespace std;

int T;
long long n;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> n;
    cout << (long long)(n * 2 - 1) * (long long)n + 1ll << '\n';
  }
  return 0;
 }
