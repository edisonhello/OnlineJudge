#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int s[50];
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  sort(s, s + n);
  int th = s[n - k];
  int m = 0;
  for (int i = 0; i < n - k; ++i) {
    if (s[i] <= th) m++;
  }
  cout << n - m << endl;
  return 0;
}
