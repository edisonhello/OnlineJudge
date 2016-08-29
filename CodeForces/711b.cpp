#include <iostream>
using namespace std;

int sq[500][500];

int main() {
  int n;
  cin >> n;
  int zi, zj;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> sq[i][j];
      if (sq[i][j] == 0) {
        zi = i;
        zj = j;
      }
    }
  }
  int sum = 0;
  int r;
  if (zi == 0) r = 1;
  else r = zi - 1;
  for (int i = 0; i < n; ++i) {
    sum += sq[r][i];
  }
  int jizz = 0;
  for (int i = 0; i < n; ++i) {
    jizz += sq[zi][i];
  }
  int ans = sum - jizz;

  bool yes = true;
  int zz = 0;
  for (int i = 0; i < n; ++i) {
    zz += sq[i][zj];
  }
  if (zz + ans != sum) yes = false;
  zz = 0;
  int zzz = 0;
  if (zi == zj || zi + zj == n) {
    for (int i = 0; i < n; ++i) {
      zz += sq[i][i];
      zzz += sq[n - i - 1][i];
    }
    if (zz + ans != sum || zzz + ans != sum) yes = false;
  } else {
    for (int i = 0; i < n; ++i) {
      zz += sq[i][i];
      zzz += sq[n - i - 1][i];
    }
    if (zzz != sum || zz != sum) yes = false;
  }
  for (int i = 0; i < n; ++i) {
    if (i == zi) continue;
    zz = 0;
    for (int j = 0; j < n; ++j) zz += sq[i][j];
    if (zz != sum) yes = false;
  }
  for (int i = 0; i < n; ++i) {
    if (i == zj) continue;
    zz = 0;
    for (int j = 0; j < n; ++j) {
      zz += sq[j][i];
    }
    if (zz != sum) yes = false;
  }
  // zz = 0;
  // zzz = 0;
  // for (int i = 0; i < n; ++i) {
  //   zz += sq[i][i];
  //   zzz += sq[n - i - 1][i];
  // }
  if (zz + ans != sum || zzz + ans != sum) yes = false;
  if (yes)
    cout << ans << endl;
  else
    cout << -1 << endl;
  return 0;
}
