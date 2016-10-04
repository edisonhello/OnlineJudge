#include <iostream>
#include <cmath>
using namespace std;

long long int N, ans;

int log3(long long int n) {
  int l = 1, r = n;
  int m = (l + r) / 2;
  while (l < r) {
    if (pow(3, m) <= n && pow(3, m + 1) > n) return m;
    else if (pow(3, m) > m) r = m - 1;
    else l = m + 1;
    m = (l + r) / 2;
  }
  return l;
}

int main() {
  while (cin >> N) {
    cout << N << endl;
    ans = 0;
    for (long long int i = 3; i <= N - N % 3; i += 3) ans += log3(i);
    cout << ans << endl;
  }
  return 0;
}
