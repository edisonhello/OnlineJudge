#include <iostream>
using namespace std;

int main() {
  int n;
  int n1;
  int t;
  int sum;
  while (true) {
    cin >> n;
    if (n == 0) break;
    n1 = n;
    sum = n;
    t = 1;
    while (true) {
      cin >> n;
      if (n == 0) break;
      t++;
      sum += n;
    }
    cout << n1 << ' ' << t << ' ' << sum << endl;
  }
  return 0;
}
