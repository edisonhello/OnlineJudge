#include <iostream>
#include <fstream>
using namespace std;

const int MOD = 1000000007;
long long A[3] = {1, 1, 1}, m[3][3] = { {0, 0, 3}, {1, 0, 2}, {0, 1, 1} }, tmp[3], tmpm[3][3];
long long N;

int main() {
  // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
  cin >> N; N--;
  for (; N; N /= 2) {
    if (N & 1) {
      for (int i = 0; i < 3; ++i) tmp[i] = A[i];
      for (int j = 0; j < 3; ++j) {
        A[j] = 0;
        for (int k = 0; k < 3; ++k) {
          A[j] += tmp[k] * m[k][j];
          A[j] %= MOD;
        }
      }
      // for (int i = 0; i < 3; ++i) cout << A[i] << ' ';
      // cout << endl;
    }
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) tmpm[i][j] = m[i][j];
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        m[i][j] = 0;
        for (int k = 0; k < 3; ++k) {
          m[i][j] += tmpm[i][k] * tmpm[k][j];
          m[i][j] %= MOD;
        }
      }
    }
  }
  cout << A[0] % MOD << endl;
  return 0;
}
