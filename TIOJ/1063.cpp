#include <iostream>
using namespace std;

int m, n, a[205][205], cnt;

int main() {
  cin >> m >> n;
  for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
  for (int i = 0; i < m; ++i) {
    for (int j = i; j < m; ++j) {
      cnt = 0;
      for (int k = 0; k < n; ++k) {
        if (a[j][k] == 0) cnt = 0, continue;
        else cnt++;
      }
    }
  }
}
