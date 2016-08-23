#include <iostream>
using namespace std;

int main() {
  int T, n, m, score;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    int min = 200000000;
    int max = 0;
    for (int i = 1; i < n; ++i) {
      cin >> score;
      if (score > m && score < min) min = score;
      if (score < m && score > max) max = score;
    }
    cout << min << ' ' << max << endl;
  }
  return 0;
}
