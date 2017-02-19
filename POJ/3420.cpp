#include <bits/stdc++.h>
using namespace std;

int N, M;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> N >> M, (N || M)) {
    int a[2] = { 0, 1 };
    int b[2][2] = {{ 0, 6 }, { 1, 1 }};
    for (; N; N >>= 1) {
      if (N & 1) {
        int tmp[2];
        for (int i = 0; i < 2; ++i) tmp[i] = a[i], a[i] = 0;
        for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k) a[j] += tmp[k] * b[k][j], a[j] %= M;
      }
      int tmp[2][2];
      for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) tmp[i][j] = b[i][j], b[i][j] = 0;
      for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k) {
        b[i][j] += tmp[i][k] * tmp[k][j]; b[i][j] %= M;
      }
    }
    cout << a[0] << '\n';
  }
  return 0;
}
