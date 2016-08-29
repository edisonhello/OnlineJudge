#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n, a;
  int x[100000];
  cin >> n >> a;
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  sort(x, x + n);
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  long long int dis = 0;
  
}
