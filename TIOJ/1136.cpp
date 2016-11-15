#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
using namespace std;

int N, T, C, s, t, mat[105][105], tmp[105][105], ans[105][105], X;
double tot, p;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  while (cin >> N >> T, (N || T)) {
    cin >> C;
    memset(mat, 0, sizeof(mat));
    while (C--) {
      cin >> s >> t;
      mat[s][t] = 1; mat[t][s] = 1;
    }
    cin >> X;
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= N; ++i) ans[i][i] = 1;
    for (; T; T /= 2) {
      if (T & 1) {
        for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) tmp[i][j] = ans[i][j], ans[i][j] = 0;
        for (int i = 1; i <= N; ++i) {
          for (int j = 1; j <= N; ++j) {
            for (int k = 1; k <= N; ++k) {
              ans[i][j] += tmp[i][k] * mat[j][k];
            }
          }
        }
      }
      for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) tmp[i][j] = mat[i][j], mat[i][j] = 0;
      for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
          for (int k = 1; k <= N; ++k) {
            mat[i][j] += tmp[i][k] * tmp[j][k];
          }
        }
      }
    }
    tot = 0.0; p = 0.0;
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) {
      if (j == X) p += ans[i][j];
      tot += ans[i][j];
    }
    cout << fixed << setprecision(4) << p / tot << endl;
  }
  return 0;
}
