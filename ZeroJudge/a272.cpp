#include <bits/stdc++.h>
using namespace std;

const int MOD = 10007;
int N;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> N) {
    int b[2][2] = {{ 1, 1 }, { 1, 0 }}, a[2][2] = {{ 1, 0 }, { 0, 1 }};
    for (; N; N >>= 1) {
      if (N & 1) {
        int tmp[2][2];
        for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) tmp[i][j] = a[i][j], a[i][j] = 0;
        for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) {
          for (int k = 0; k < 2; ++k) a[i][j] = (a[i][j] + tmp[i][k] * b[k][j]) % MOD;
        }
      }
      int tmp[2][2];
      for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) tmp[i][j] = b[i][j], b[i][j] = 0;
      for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) b[i][j] = (b[i][j] + tmp[i][k] * tmp[k][j]) % MOD;
      }
    }
    cout << a[0][0] << '\n';
  }
  return 0;
}
