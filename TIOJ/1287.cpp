#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int v[1000010];
int n;

int main() {
  while (cin >> n) {
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v, v + n);
    for (int i = 0; i < n; ++i) cout << v[i] << ' ';
    cout << endl;
  }
  return 0;
}
