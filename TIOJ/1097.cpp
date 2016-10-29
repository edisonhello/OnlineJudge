#include <iostream>
#include <cstring>
using namespace std;

short mp[5005][5005], x, dp[5005][5005], s[5005];
int L, W;

int main() {
  while (cin >> L >> W, (L || W)) {
    for (int i = 0; i < L; ++i) {
      for (int j = 0; j < W; ++j) {
        cin >> x;
        mp[i][j] = (x == 2) ? 1 : 0;
      }
    }
    for (int j = 0; j < W; ++i) {
      dp[0][j] = mp[0][j];
      for (int i = 1; i < L; ++i) {
        dp[i][j] = dp[0][j] + mp[i][j];
      }
    }
    for (int i = 0; i < L; ++i) {
      for (int j = i; j < L; ++j) {
        for (int k = 0; k < j - i + 1; ++k) {

        }
      }
    }
  }
}
