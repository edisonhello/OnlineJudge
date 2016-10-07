#include <iostream>
using namespace std;

long long dp[15];

long long f(int n) {
  if (n == 1) return dp[1] = 1;
  return dp[n] = n * f(n - 1);
}

string s;
int n, m;
int main() {
  while (cin >> n >> m) {
    if (n == 0 && m == 0) break;
    m %= f(n);
    s = "";
    while (n > 1) {
      cout << "m: " << m << endl;
      cout << "dp[n - 1]: " << dp[n] << endl;
      s += (char)(m / dp[n] + 65);
      m %= dp[n];
      n--;
    }
    cout << s << endl;
  }
  return 0;
}
