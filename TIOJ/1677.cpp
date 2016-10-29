#include <iostream>
#include <string>
using namespace std;

unsigned long long int m, n, k;
string pre, pree, nw;

int main() {
  cin >> m;
  while (m--) {
    cin >> n >> k;
    nw = ""; pre = "1"; pree = "0";
    for (int i = 2; i <= n; ++i) {
      nw = pre + pree;
      pree = pre;
      pre = nw;
    }
    if (k >= nw.size()) cout << -1 << endl;
    else cout << nw[k] << endl;
  }
  return 0;
}
