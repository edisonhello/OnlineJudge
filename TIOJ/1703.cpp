#include <iostream>
#include <cmath>
using namespace std;

int N, ans;

int main() {
  while (cin >> N) {
    ans = 0;
    for (int i = 1; pow(3, i) <= N; ++i) ans += N / pow(3, i);
    cout << ans << '\n';
  }
  return 0;
}
