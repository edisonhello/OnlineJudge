#include <iostream>
#include <algorithm>
using namespace std;

long long int N, a, b, c, mx;
int main() {
  cin >> N;
  while (N--) {
    cin >> a >> b >> c;
    mx = max(a, max(b, c));
    if (a <= 0 || b <= 0 || c <= 0) cout << "no" << endl;
    else if (mx == a) {
      if (b * b + c * c == a * a) cout << "yes" << endl;
      else cout << "no" << endl;
    } else if (mx == b) {
      if (a * a + c * c == b * b) cout << "yes" << endl;
      else cout << "no" << endl;
    } else {
      if (a * a + b * b == c * c) cout << "yes" << endl;
      else cout << "no" << endl;
    }
  }
  return 0;
}
