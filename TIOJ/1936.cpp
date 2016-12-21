#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1024;
int A[maxn][maxn], B[maxn][maxn], C[maxn][maxn], N, T, ans[maxn][maxn];
bool loli;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) cin >> A[i][j];
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) cin >> B[i][j];
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) cin >> C[i][j];
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        for (int k = 0; k < N; ++k) {
          ans[i][j] += A[i][k] * B[k][j];
        }
      }
    }
    loli = true;
    for (int i = 0; i < N && loli; ++i) for (int j = 0; j < N && loli; ++j) {
      if (ans[i][j] != C[i][j]) loli = false;
    }
    if (loli) cout << "Loli is god.\n";
    else cout << "QAQ!\n";
  }
  return 0;
}
