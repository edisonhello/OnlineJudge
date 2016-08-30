#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;
int c[100];
int p[100][100];

int minp(int x) {
  int ret = 200000000;
  for (int i = 0; i < n; ++i) {
    if (p[a][i] < ret) ret = p[a][i];
  }
  return ret;
}

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> p[i][j];
    }
  }

  int dp[100];

  if (!dp[0]) dp[0] = minp(0);
  k--;
  for (int i= 1; i < n; ++i) {
    
  }
}
