#include <iostream>
#include <cstring>
using namespace std;

int mat[50][50];
int s[50];

int main() {
  int rn, cn;
  while (cin >> rn >> cn) {
    for (int i = 0; i < rn; ++i) for (int j = 0; j < cn; ++j) cin >> mat[i][j];
    int mx = -1e9;
    for (int )
    for (int i = 0; i < rn; ++i) {
      memset(s, 0, sizeof(s));
      for (int j = i; j < rn; ++j) {
        s[0] = mat[j][0];
        for (int k = 1; k < cn; ++k) {
          s[k] += mat[j][k] + s[k - 1];
          if (s[k] > mx) mx = s[k];
        }
      }
    }
    cout << mx << endl;
  }
  return 0;
}
