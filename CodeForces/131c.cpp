#include <iostream>
#define ull unsigned long long int
using namespace std;

ull c(ull, ull);
ull f(ull);

int main() {
  ull n, m, t;
  cin >> n >> m >> t;

  ull ans = 0;

  for (ull i = 1; i <= t; ++i) {
    if (t - i < 4) break;
    ans += c(m, i) * c(n, t - i);
  }

  cout << ans << endl;
  return 0;
}

ull f(ull n) {
  if (n > 1) {
    return f(n - 1) * n;
  } else {
    return 1;
  }
}

ull c(ull n, ull k) {
  return f(n) / (f(k) * f(n - k));
}
