#include <iostream>
using namespace std;

long long int sq[500][500];
long long int n;
long long int sum = 0;

bool b() {
  long long int ji;
  for (long long int i = 0; i < n; ++i) {
    ji = 0;
    for (long long int j = 0; j < n; ++j) {
      ji += sq[i][j];
    }
    if (ji != sum) return false;
  }
  for (long long int i = 0; i < n; ++i) {
    ji = 0;
    for (long long int j = 0; j < n; ++j) {
      ji += sq[j][i];
    }
    if (ji != sum) return false;
  }
  ji = 0;
  for (long long int i = 0; i < n; ++i) {
    ji += sq[i][i];
  }
  if (ji != sum) return false;
  ji = 0;
  for (long long int i = 0; i < n; ++i) {
    ji += sq[i][n - i - 1];
  }
  if (ji != sum) return false;
  return true;
}

int main() {
  cin >> n;
  long long int zi, zj;
  for (long long int i = 0; i < n; ++i) {
    for (long long int j = 0; j < n; ++j) {
      cin >> sq[i][j];
      if (sq[i][j] == 0) {
        zi = i;
        zj = j;
      }
    }
  }
  long long int r, c;
  if (zi == n - 1) r = 0;
  else r = zi + 1;
  if (zj == n - 1) c = 0;
  else c = zj + 1;
  long long int s1, s2;
  for (long long int i = 0; i < n; ++i) {
    s1 += sq[r][i];
    s2 += sq[i][c];
  }
  if (s1 == s2) sum = s1;
  else {
    cout << -1 << endl;
    return 0;
  }
  long long int ji = 0; long long int zz = 0;
  for (long long int i = 0; i < n; ++i) {
    ji += sq[zi][i];
  }
  long long int ans = sum - ji;
  // if (ans == 0) {
  //   cout << -1 << endl;
  //   return 0;
  // }
  sq[zi][zj] = ans;
  if (b())
    cout << ans << endl;
  else
    cout << -1 << endl;
  return 0;
}
