#include <iostream>
#include <cmath>
using namespace std;

int dpa[10000005], n, a;
int dp(int);

int main() {
  cin >> n;
  while (n--) {
    cin >> a;
    cout << dp(a) << endl;
  }
  return 0;
}

int dp(int x) {
  if (x == 1) return 1;
  if (dpa[x]) return dpa[x];
  int d = 2;
  for (int i = 2; i <= x; ++i) {
    if (x % i == 0) dpa[x] += dp(x / i);
  }
  return dpa[x];
}
