#include <iostream>
using namespace std;

int main() {
  int n, k;
  int c[100000];
  int cap[100000];
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }

  for (int i = 0; i < k; ++i) {
    cin >> cap[i];
  }

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    if (i != n - 1) {
      sum += c[i] * c[i + 1];
    } else {
      sum += c[n - 1] * c[0];
    }
  }
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j != cap[i] - 1 && j != cap[i] - 2 && j != cap[i]) {
        sum += (c[cap[i]] - 1) * c[j];
      }
    }
  }
  cout << sum << endl;
  return 0;
}
