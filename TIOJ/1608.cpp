#include <iostream>
#include <utility>
#define INF (1 << 30)
using namespace std;

int n, m;
int f[1005][1005], mx, mi, mj, cnt;
int climb(int, int);
bool v[1005][1005];
// pair<int, int> p;
int d[] = {-1, 0, 1, 0, 0, -1, 0, 1};

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> f[i][j];
      if (f[i][j] > mx) mx = f[i][j], mi = i, mj = j;
    }
  }
  cout << "mi: " << mi << " mj: " << mj << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << "jizz" << endl;
      if (!v[i][j]) cnt += climb(i, j);
    }
  }
  cout << cnt << endl;
  return 0;
}


int climb(int i, int j) {
  int ri = i, rj = j;
  int ret = 0;
  while (true) {
    cout << "i: " << i << " j: " << j << endl;
    if (!v[i][j]) v[i][j] = true;
    else break;
    int mxx = -INF, mmi, mmj;
    for (int ii = 0; ii < 4; ++ii) {
      if (i + d[ii * 2] >= 0 && i + d[ii * 2] < n && j + d[ii * 2 + 1] >= 0 && j + d[ii * 2 + 1] < m) {
        if (f[i + d[ii * 2]][j + d[ii * 2 + 1]] > mxx && f[i + d[ii * 2]][j + d[ii * 2 + 1]] > f[i][j]) {
          mxx = f[i + d[ii * 2]][j + d[ii * 2 + 1]];
          mmi = i + d[ii * 2]; mmj = j + d[ii * 2 + 1];
        }
      }
    }
    if (mxx == -INF) break;
    ret++;
    i = mmi; j = mmj;
  }
  // if (v[i][j]) ret--;
  if (i == mi && j == mj) ret = 0;
  cout << "ret: " << ret << endl;
  return ret;
}
