#include <iostream>
#include <cstring>
using namespace std;

int mp1[10005], mp2[10005], w[2][10005], len, mlen, xlen, i, j, k, r;
long long cnt;

int main() {
  int n, m, p, q, x;
  cin >> n >> m >> p >> q;
  for (int i = 0; i < m; ++i) cin >> mp1[i];
  for (int i = 1; i < m; ++i) cin >> mp2[i];
  mp2[0] = mp1[0];
  cnt = (m - 1) * (m - 1);
  for (i = 0; i < m; ++i) {
    if (i) {
      w[i % 2][0] = mp2[i];
      for (r = 1; r < m; ++r) w[i % 2][r] = w[(i + 1) % 2][r - 1] ^ w[(i + 1) % 2][r] ^ w[i % 2][r - 1];
    } else {
      for (r = 0; r < m; ++r) w[i % 2][r] = mp1[r];
    }
    for (j = 0; j < m; j = k) {
      for (k = j + 1; k < m && w[i % 2][k] >= w[i % 2][k - 1]; ++k) {}
      len = k - j;
      if (len >= p) {
        if (p == q) cnt += len - (p - 1);
        else if (len <= q) len -= (p - 1), cnt += len * (len + 1) / 2;
        else {
          mlen = len - (p - 1);
          xlen = len - (q - 1);
          cnt += (mlen + xlen) * (mlen - xlen + 1) / 2;
        }
      }
    }
  }
  memset(w, 0, sizeof(w));
  for (i = 0; i < m; ++i) {
    if (i) {
      w[i % 2][0] = mp1[i];
      for (r = 1; r < m; ++r) w[i % 2][r] = w[(i + 1) % 2][r - 1] ^ w[(i + 1) % 2][r] ^ w[i % 2][r - 1];
    } else {
      for (r = 0; r < m; ++r) w[i % 2][r] = mp2[r];
    }
    for (j = 0; j < m; j = k) {
      for (k = j + 1; k < m && w[i % 2][k] >= w[i % 2][k - 1]; ++k) {}
      len = k - j;
      if (len >= p) {
        if (p == q) cnt += len - (p - 1);
        else if (len <= q) len -= (p - 1), cnt += len * (len + 1) / 2;
        else {
          mlen = len - (p - 1);
          xlen = len - (q - 1);
          cnt += (mlen + xlen) * (mlen - xlen + 1) / 2;
        }
      }
    }
  }
  cout << cnt % n << endl;
  return 0;
}
