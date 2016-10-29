#include <iostream>
#include <algorithm>
using namespace std;

int d[10000], n, tot;

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> d[i];
  sort(d, d + n);
  for (int i = 0; i < n; ++i) {
    tot += (d[i] - d[i - 1]) * (d[i] - d[i - 1]);
  }
  cout << tot << endl;
  return 0;
}
