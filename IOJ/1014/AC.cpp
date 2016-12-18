#include <iostream>
#include <fstream>
using namespace std;

const int MOD = 1000000007;
long long A[101], m[101][101], tmp[101], tmpm[101][101], k[101];
long long N, M;

int main() {
  // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
  cin >> N >> M; N--;
  for (int i = M - 1; i >= 0; --i) cin >> m[i][M - 1];
  for (int i = M - 2; i >= 0; --i) m[i + 1][i] = 1;
  for (int i = 0; i < M; ++i) A[i] = 1;
  for (; N; N /= 2) {
    if (N & 1) {
      for (int i = 0; i < M; ++i) tmp[i] = A[i];
      for (int j = 0; j < M; ++j) {
        A[j] = 0;
        for (int k = 0; k < M; ++k) {
          A[j] += tmp[k] * m[k][j];
          A[j] %= MOD;
        }
      }
      // for (int i = 0; i < 3; ++i) cout << A[i] << ' ';
      // cout << endl;
    }
    for (int i = 0; i < M; ++i) for (int j = 0; j < M; ++j) tmpm[i][j] = m[i][j];
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < M; ++j) {
        m[i][j] = 0;
        for (int k = 0; k < M; ++k) {
          m[i][j] += tmpm[i][k] * tmpm[k][j];
          m[i][j] %= MOD;
        }
      }
    }
  }
  cout << A[0] % MOD << endl;
  return 0;
}
