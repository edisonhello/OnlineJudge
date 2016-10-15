#include <iostream>
#include <cstring>
using namespace std;

string s;
int n, m;
int dp[15], a, b, cnt;
bool v[26];

long long f(int n) {
  if (dp[n]) return dp[n];
  if (n == 1 || n == 0) return dp[n] = 1;
  return dp[n] = n * f(n - 1);
}
int main() {
  while (cin >> n >> m, (n || m)) {
    memset(v, false, sizeof(v));
    m--;
    m %= f(n);
    for (int i = 0; i < n; ++i) {
      a = m / f(n - i - 1);
      m %= f(n - i - 1);
      cnt = 0;
      for (int j = 0; j < n; ++j) {
        if (!v[j] && cnt == a) {
          cout << (char)(j + 'A') << ' ';
          v[j] = true;
          break;
        }
        if (!v[j]) cnt++;
      }
    }
    cout << endl;
    // cout << s << endl;
  }
  return 0;
}
