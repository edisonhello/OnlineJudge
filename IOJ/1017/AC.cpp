#include <iostream>
#include <fstream>
using namespace std;

int c[101], x, n;

int main() {
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> x, c[x]++;
  for (int i = 1; i <= 100; ++i) {
    for (int j = 0; j < c[i]; ++j) cout << i << ' ';
  }
  return 0;
}
