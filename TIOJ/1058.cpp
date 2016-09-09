#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  string aa[2];
  string bb[2];
  int i = 0;
  int idx = 0;
  while (i < a.length()) {
    if (a[i] == '.') idx++;
    aa[idx] += a[i];
    i++;
  }
  i = 0;
  idx = 0;
  while (i < b.length()) {
    if (b[i] == '.') idx++;
    bb[idx] += b[i];
    i++;
  }
  if (aa[0].length() > bb[0].length()) {
    cout << a << endl;
    return 0;
  }
  if (bb[0].length() > aa[0].length()) {
    cout << b << endl;
    return 0;
  }
  if (aa[0] > bb[0]) {
    cout << a << endl;
    return 0;
  }
  if (aa[0] < bb[0]) {
    cout << b << endl;
    return 0;
  }
  for (int j = 0; j < max(aa[1].length(), bb[1].length()); ++j) {
    if (aa[1][j] > bb[1][j]) {
      cout << a << endl;
      return 0;
    } else if (bb[1][j] > aa[1][j]) {
      cout << b << endl;
      return 0;
    }
  }
  return 0;
}
