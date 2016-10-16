#include <iostream>
using namespace std;

long long dp[20];

long long f(int n) {
  if (dp[n]) return dp[n];
  if (n == 0 || n == 1) return dp[n] = 1;
  return dp[n] = f(n - 1) * n;
}

long long C(int n, int k) {
  return f(n) / (f(n - k) * f(k));
}

int n, k;
long long cnt;

int main() {
  while (cin >> n, n) {
    cnt = 0;
    // cout << "C: " << C(n, 2) << endl;
    k = 1;
    for (int i = 0; i <= n; ++i) {
      cnt += k * C(n, i) * f(n - i);
      k = -k;
    }
    cout << cnt << endl;
  }
  return 0;
}
