#include <iostream>
#include <cstring>
using namespace std;

int r[2][1000];
int c[2][1000];

int main() {
  int n, m, p, q, x;
  int cnt = 0;
  cin >> n >> m >> p >> q;
  for (int i = 0; i < m; ++i) {
    cin >> x;
    r[0][i] = x;
  }
  c[0][0] = r[0][0];
  for (int i = 1; i < m; ++i) {
    cin >> x;
    c[0][i] = x;
  }
  c[1][0] = j[0][1];
  for (int i = 0; i < m; ++i) {

  }
  for (int i = 1; i < m; ++i) {
    for (int j = 1; j < m; ++j) {
      r[1][j] = r[1][j - 1] ^ r[0][j - 1] ^ r[0][j];
    }
    for ()
  }
}
