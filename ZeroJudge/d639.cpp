#include <iostream>
using namespace std;

const int MOD = 10007;
int mat[3][3] = {{1, 1, 0}, {1, 0, 1}, {1, 0, 0}};
int ans[3], tmp1[3][3], tmp[3];
int n;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < 3; ++i) ans[i] = 1;
  n--;
  for (; n; n /= 2) {
    if (n & 1) {
      for (int i = 0; i < 3; ++i) tmp[i] = ans[i], ans[i] = 0;
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
          ans[j] += tmp[k] * mat[k][j]; ans[j] %= MOD;
        }
      }
    }
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) tmp1[i][j] = mat[i][j], mat[i][j] = 0;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
          mat[i][j] += tmp1[i][k] * tmp1[k][j]; mat[i][j] %= MOD;
        }
      }
    }
  }
  cout << ans[2] % MOD << endl;
  return 0;
}
