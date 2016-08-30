#include <iostream>
using namespace std;

int main() {
  int n, t;
  cin >> n >> t;
  int a[10000];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int j;
  int ti;
  int max = 0;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    j = i;
    ti = t;
    cnt = 0;
    while (ti >= a[j] && j < n) {
      ti -= a[j++];
      cnt++;
    }
    if (cnt > max) max = cnt;
  }
  cout << max << endl;
  return 0;
}
