#include <iostream>
using namespace std;

int x[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int y[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int r, c, cnt;
int mp[100][100];

int main() {
  while (cin >> r >> c) {
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        cin >> mp[i][j];
      }
    }
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (mp[i][j] == 1) cout << "X ";
        else {
          cnt = 0;
          for (int k = 0; k < 8; ++k) {
            if (i + y[k] < r && i + y[k] >= 0 && j + x[k] < c && j + x[k] >= 0 && mp[i + y[k]][j + x[k]] == 1) cnt++;
          }
          cout << cnt << ' ';
        }
      }
      cout << endl;
    }
  }
  return 0;
}
