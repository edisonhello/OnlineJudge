#include <iostream>
#include <cstring>
using namespace std;

int N, M, dp[210][210], mp[210][210], s[210], lm, mx, value;
bool p;

int main() {
  cin >> M >> N;
  for (int i = 0; i < M; ++i) for (int j = 0; j < N; ++j) cin >> mp[i][j];
  for (int j = 0; j < N; ++j) {
    dp[0][j] = mp[0][j];
    for (int i = 1; i < M; ++i) {
      dp[i][j] = dp[i - 1][j] + mp[i][j];
    }
  }
  mx = 0;
  for (int i = 0; i < M; ++i) {
    for (int j = i; j < M; ++j) {
      memset(s, 0, sizeof(s));
      lm = 0;
      s[0] = dp[j][0] - (i == 0 ? 0 : dp[j - 1][0]);
      p = true;
      for (int k = 1; k < N; ++k) {
        if (mp[j][k] == 0) {p = false; continue;}
        value = dp[j][k] - (i == 0 ? 0 : dp[j - 1][k]);
        if (value == 0) {p = false; break;}
        if (s[k - 1] > 0) s[k] = s[k - 1] + value;
        else s[k] = value;
        if (s[k] > s[lm]) lm = k;
      }
      if (s[lm] > mx && p) mx = s[lm];
    }
  }
  cout << mx << endl;
}
