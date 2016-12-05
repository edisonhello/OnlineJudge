#include <iostream>
#include <bitset>
#define endl '\n'
using namespace std;

bitset<1048576> dp;
int N, x, mx;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  while (cin >> N, N) {
    dp.reset();
    dp[0] = true;
    for (int i = 0; i < N; ++i) {
      cin >> x;
      for (int j = 0; j < 1048576; ++j) if (dp[j]) dp[j ^ x] = true;
    }
    for (int i = 0; i < 1048576; ++i) {
      if (dp[i]) mx = i;
    }
    cout << mx << endl;
  }
  return 0;
}
