#include <iostream>
using namespace std;

int n, m;
int __pow(int n, int m) {
  int ret = 1;
  for (int i = 0; i < m; ++i) {
    ret *= n;
    ret %= 1000000;
  }
  return ret;
}

int main() {
  while (cin >> n >> m, (n || m)) {
    cout << __pow(n, m) << endl;
  }
  return 0;
}
