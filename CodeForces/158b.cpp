#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n;
  int s[10000];
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  // cout << "jizz" << endl;
  sort(s, s + n);
  int taxi = 0;
  int cur = 0;
  int idx = 0;
  while (idx < n) {
    if (cur + s[idx] <= 4) {
      cur += s[idx];
      idx++;
    } else {
      cur = 0;
      taxi++;
      // i--;
    }
  }
  if (cur > 0) taxi++;
  cout << taxi << endl;
  return 0;
}
